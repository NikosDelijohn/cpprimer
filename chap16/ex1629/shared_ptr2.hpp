#pragma once

#include <cassert>

#ifndef NDEBUG
struct trace {
    trace(const char* name) : name(name) {
        std::cout << "[enter] " << name << '\n';
    }
    ~trace() {
        std::cout << "[exit ] " << name << '\n';
    }
    const char* name;
};
#define TRACE() trace _trace(__func__)
#else
#define TRACE() ((void)0)
#endif

namespace msp
{

template <typename Type>
struct default_deleter
{
    void operator()(Type* obj) { TRACE(); delete obj; }
};

template <typename Type>
struct custom_deleter
{
    void operator()(Type* obj) { TRACE(); deleter(obj); }
    void (*deleter)(Type*);
};

template <typename Type>
class control_block_base
{
public:

    control_block_base() = default;
    virtual ~control_block_base() = default;
    
    void ref_incr() { TRACE(); ++ref_count; }
    void ref_decr() { TRACE(); --ref_count; }

    size_t get_ref () const {TRACE(); return ref_count;}
    size_t ref_count = 1u;
};

template <typename Type, typename Deleter=default_deleter<Type>>
class control_block_external: public control_block_base<Type>
{
public:
    
    control_block_external(Type* pointee, Deleter deleter = Deleter{}): 
        pointee(pointee), deleter(std::move(deleter))
    {TRACE();}
    virtual ~control_block_external() override { TRACE(); deleter(pointee); }

private:
    Type* pointee;
    Deleter deleter;
};

template <typename Type>
class shared_ptr
{
public:
    explicit shared_ptr(Type* pointee):
        pointee(pointee),
        cb(pointee? new control_block_external<Type>(pointee): nullptr)
    {TRACE();}

    shared_ptr(Type* pointee, void (*deleter)(Type*)):
        pointee(pointee),
        cb(pointee? new control_block_external<Type, custom_deleter<Type>>(pointee, {deleter}): nullptr)
    {TRACE();}
    
    shared_ptr(const shared_ptr& other):
        pointee(other.pointee),
        cb(other.cb)
    {
        TRACE();
        if (cb)
            cb->ref_incr();
    }

    shared_ptr(shared_ptr&& other) noexcept:
        pointee(other.pointee),
        cb(other.cb)
    {
        TRACE();
        other.cb = nullptr;
        other.pointee = nullptr;
    }

    ~shared_ptr() { TRACE(); relinquish(); }

    shared_ptr& operator=(const shared_ptr& other)
    {
        TRACE();

        if (this != &other)
        {

            relinquish();

            if (other.cb)
                other.cb->ref_incr();
            
            cb = other.cb;
            pointee = other.pointee;
        }
        return *this;
    }

    shared_ptr& operator=(shared_ptr&& other) noexcept
    {
        TRACE();

        if (this != &other)
        {
            relinquish();

            cb = other.cb;
            pointee = other.pointee;

            other.cb = nullptr;
            other.pointee = nullptr;
        }
        return *this;        
    }

    size_t get_uses() const { TRACE(); return cb->get_ref(); }

    void reset() { TRACE(); relinquish(); }
    void reset(Type* ptr)
    {
        TRACE();

        relinquish();

        if (ptr)
        {
            pointee = ptr;
            cb = new control_block_external<Type>(ptr);
        }
    }
    void reset(Type* ptr, void (*deleter)(Type*))
    {
        TRACE();

        relinquish();

        if (ptr)
        {
            pointee = ptr;
            cb = new control_block_external<Type, custom_deleter<Type>>(ptr, {deleter});
        }
    }

    Type* operator->() const noexcept
    {
        assert(pointee);
        return pointee;
    }

    Type& operator*() const noexcept
    {
        assert(pointee);
        return *pointee;
    }

    Type* get() const noexcept {TRACE(); return pointee;}

private:

    void relinquish()
    {
        if(!cb) return;

        cb->ref_decr();
        if (cb->get_ref() == 0)
            delete cb;

        cb = nullptr;
        pointee = nullptr;
    }

    Type* pointee;
    control_block_base<Type>* cb;
};

};
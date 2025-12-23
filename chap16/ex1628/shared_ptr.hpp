#pragma once

// Thread UNSAFE

namespace msp
{

template <typename Type>
void default_delete(void* ptr)
{
    delete static_cast<Type*>(ptr);
}

template <typename Pointee>
class control_block
{

public:

    explicit control_block(Pointee* pointee): 
        ref_count(1u),
        pointee(pointee),
        deleter(&default_delete<Pointee>)
    {}

    control_block(Pointee* pointee, void(*deleter)(void *)):
        ref_count(1u),
        pointee(pointee),
        deleter(deleter)
    {}
    
    void destroy()
    {
#ifndef NDEBUG
        std::cout << __func__ << ": Destroying object!\n";
#endif
        deleter(static_cast<void*>(pointee));

    }

    ~control_block() = default;        
    unsigned ref_count;

private:

    Pointee* pointee;
    void (*deleter)(void*);

};

template <typename Pointee>
class shared_ptr
{

public:

    shared_ptr(Pointee* ptr):
        pointee(ptr),
        cb(ptr ? new control_block<Pointee>(ptr) : nullptr)
    {}
    
    shared_ptr(Pointee* ptr, void (*deleter)(void*))
        : pointee(ptr),
        cb(ptr ? new control_block<Pointee>(ptr, deleter) : nullptr)
    {}
    
    shared_ptr(const shared_ptr& other):
        pointee(other.pointee),
        cb(other.cb)
    {
        if (cb)
            ++cb->ref_count;
    } 

    shared_ptr(shared_ptr&& other) noexcept:
        pointee(other.pointee),
        cb(other.cb)
    {
        other.pointee = nullptr;
        other.cb = nullptr;
    }

    ~shared_ptr() { relinquish(); }

    shared_ptr& operator=(const shared_ptr& rhs)
    {
        if (this != &rhs)
        {
            relinquish();
        
            pointee = rhs.pointee;
            cb = rhs.cb;

            if (cb)
                ++cb->ref_count;
        }

        return *this;
    }

    shared_ptr& operator=(shared_ptr&& rhs) noexcept
    {
        if (this != &rhs)
        {
            relinquish();
        
            pointee = rhs.pointee;
            cb = rhs.cb;

            rhs.pointee = nullptr;
            rhs.cb = nullptr;
        }

        return *this;
    }    
        
    unsigned get_uses() const noexcept
    {
        return cb ? cb->ref_count : 0u;
    }

    inline Pointee& operator*() const noexcept
    {
        assert(pointee);
        return *pointee;
    }

    inline Pointee* operator->() const noexcept
    {
        assert(pointee);
        return &this->operator*();
    }

private:

    void relinquish()
    {
        if (!cb)
            return;
        
        if (--cb->ref_count == 0)
        {
            cb->destroy();
            delete cb;
        }
        
        cb = nullptr;
        pointee = nullptr;
    }

    Pointee* pointee;
    control_block<Pointee>* cb;
};

}

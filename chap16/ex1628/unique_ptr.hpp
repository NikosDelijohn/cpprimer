#pragma once

namespace msp
{

template <typename Type>
struct default_deleter
{
    void operator()(Type* obj) { delete obj; }
};


template <typename Type, typename Deleter = default_deleter<Type>>
class unique_ptr
{

public:

    explicit unique_ptr(Type* pointee) noexcept:
        pointee(pointee),
        deleter(Deleter{})
    {}

    explicit unique_ptr(Deleter custom_deleter) noexcept:
        pointee(nullptr),
        deleter(std::move(custom_deleter))
    {}

    unique_ptr(Type* pointee, Deleter custom_deleter) noexcept:
        pointee(pointee),
        deleter(std::move(custom_deleter))
    {}

    ~unique_ptr() 
    {
        if (pointee)
            deleter(pointee);
    }

    unique_ptr(const unique_ptr& other) = delete;
    unique_ptr& operator=(const unique_ptr& other) = delete;

    unique_ptr(unique_ptr&& other) noexcept:
        pointee(other.pointee),
        deleter(std::move(other.deleter))
    {
        other.pointee = nullptr;
    }

    // u = nullptr should work deleting pointee and setting it to nullptr
    unique_ptr& operator=(std::nullptr_t) noexcept
    {
        reset();
        return *this;
    }

    unique_ptr& operator=(unique_ptr&& other) noexcept
    {
        if (this != &other)
        {
            if (pointee)
                deleter(pointee);

            pointee = other.pointee;
            deleter = std::move(other.deleter);

            other.pointee = nullptr;
        }
        return *this;
    }

    Type* operator->() const noexcept
    {
        return pointee;
    }

    Type& operator*() const noexcept
    {
        return *pointee;
    }

    Type* release() noexcept
    {
        Type* retval = pointee;
        pointee = nullptr;

        return retval;
    }

    void reset(Type* ptr = nullptr) noexcept
    {
        if (pointee != ptr)
        {
            if (pointee)
                deleter(pointee);

            pointee = ptr;
        }
    }

    Type* get() const noexcept
    {
        return pointee;
    }

private:
    Type* pointee = nullptr;
    Deleter deleter;
};

}
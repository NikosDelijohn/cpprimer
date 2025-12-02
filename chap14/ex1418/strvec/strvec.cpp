#include "strvec.hpp"
#include <algorithm>

std::allocator<std::string> strvec::alloc;

strvec::~strvec()
{
    free();
}

strvec::strvec(const strvec &other)
{
    auto new_data = alloc_and_copy(other.begin(), other.end());
    elements = new_data.first;
    first_free = cap = new_data.second;
}

strvec::strvec(strvec &&other):
    elements(std::move(other.elements)),
    first_free(std::move(other.first_free)),
    cap(std::move(other.cap))
{
#ifndef NDEBUG
    std::cout << __func__ << " Move Constructor Invoked" << std::endl;
#endif

    other.elements = other.first_free = other.cap = nullptr;

}

strvec& strvec::operator=(const strvec &rhs)
{
    if (this != &rhs)
    {
        free();
        auto new_data = alloc_and_copy(rhs.begin(), rhs.end());
        
        elements = new_data.first;
        first_free = cap = new_data.second;
    }

    return *this;
}

strvec& strvec::operator=(strvec &&rhs)
{
    if (this != &rhs)
    {
        free();

        elements = rhs.elements;
        first_free = rhs.first_free;
        cap = rhs.cap;

        rhs.elements = rhs.first_free = rhs.cap = nullptr;

    }

    return *this;
}

void strvec::push_back(const std::string& str)
{
    check_and_alloc();
    alloc.construct(first_free++, str);
}

std::pair<std::string *, std::string *>
strvec::alloc_and_copy(const std::string *b, const std::string *e)
{
    
    std::string* new_data_beg = alloc.allocate(e - b);
    // uninitialized copy returns the off-the-end ptr.
    std::string* new_data_end = std::uninitialized_copy(b, e, new_data_beg);
    return {new_data_beg, new_data_end};
}

#ifdef _OLD_
void strvec::free()
{
    if (elements)
    {
        for(std::string *it = first_free; it != elements;  )
        {
            alloc.destroy(--it);
        }

        alloc.deallocate(elements, cap - elements);
    }
}
#else
void strvec::free()
{
    if(elements)
    {
        std::for_each(begin(), end(), 
            [](std::string &str) -> void
            {
                strvec::alloc.destroy(&str);
            }
        );

        alloc.deallocate(elements, cap - elements);
    }
}
#endif

void strvec::reallocate()
{
    size_t new_capacity = (elements) ? 2 * size() : 1;

    std::string* new_data_beg = alloc.allocate(new_capacity);
    std::string* new_data_end = new_data_beg + new_capacity;

    auto src = elements;
    auto dst = new_data_beg;

    // after the loop, dst will be the new first_free
    for(size_t idx = 0u; idx < size(); ++idx)
        alloc.construct(dst++, std::move(*src++));

    /*
        A moved-from std::string is still alive and must be destroyed properly:
        Moving transfers the internal buffer pointer, but the original still holds an empty or valid state.
        Skipping destroying moved-from objects, is a leak-hazard.
        Calling destroy() on moved-from objects is correct and required.
    */
    free();

    // update pointers
    elements = new_data_beg;
    first_free = dst;
    cap = new_data_end;

}

void strvec::reserve(size_t n)
{
    if (n > capacity())
    {
        std::string* new_data_beg = alloc.allocate(n);
        std::string* new_data_end = new_data_beg + n;

        auto src = elements;
        auto dst = new_data_beg;

        for (size_t i = 0; i < size(); ++i)
            alloc.construct(dst++, std::move(*src++));

        free();

        elements = new_data_beg;
        first_free = dst;
        cap = new_data_end;
    }
}

void strvec::resize(size_t n, const std::string &str)
{
    if (n > capacity())
        reserve(n);


    if (n > size()) 
    {
        while (size() < n)
            push_back(str);
    }
    else
    {
        while (size() > n)
            alloc.destroy(--first_free);
    }

}

bool operator==(const strvec &a, const strvec &b)
{
    if (a.size() != b.size())
        return false;

    for (size_t idx = 0u; idx < a.size(); ++idx)
    {
        if (*(a.elements+idx) != *(b.elements+idx))
            return false;
    }

    return true;
    
}

bool operator!=(const strvec &a, const strvec &b)
{
    return !(a == b);
}

bool operator<(const strvec &a, const strvec &b)
{
    size_t min_size = std::min(a.size(), b.size());
    for (size_t i = 0; i < min_size; ++i)
    {
        if (*(a.elements+i) < *(b.elements+i)) 
            return true;
        if (*(a.elements+i) > *(b.elements+i)) 
            return false;
    }
    
    return a.size() < b.size();
}

bool operator<=(const strvec& a, const strvec& b)
{
    return a == b || a < b;
}

bool operator>(const strvec& a, const strvec& b)
{
    return b < a;
}

bool operator>=(const strvec& a, const strvec& b)
{
    return !(a < b);
}

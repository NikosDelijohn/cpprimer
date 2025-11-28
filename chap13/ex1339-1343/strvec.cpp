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
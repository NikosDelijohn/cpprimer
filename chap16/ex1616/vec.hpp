#pragma once

#include <iostream>
#include <memory>
#include <string>

template <class Element>
class vec
{

public:

    using value_type = Element;

    vec():
        elements(nullptr),
        first_free(nullptr),
        cap(nullptr)
    {}

    vec(std::initializer_list<value_type> il)
    {
        auto data = alloc_and_copy(il.begin(), il.end());
        
        elements = data.first;
        first_free = cap = data.second;
    }

    vec(const vec &);
    vec(vec &&) noexcept;
    ~vec();
    vec& operator=(const vec &);
    vec& operator=(vec &&) noexcept;

    void push_back(const value_type&);

    size_t size() const {return first_free - elements;}
    size_t capacity() const {return cap - elements;}
    
    void reserve(size_t);
    void resize(size_t, const value_type & = "");

    value_type *begin() const {return elements;}
    value_type *end() const  {return first_free;} // not cap, cap is pointing to raw unconstructed memory

private:
    
    std::pair<value_type*, value_type*> 
    alloc_and_copy(const value_type*, const value_type *);

    void check_and_alloc()
    {
        if (size() == capacity())
            reallocate();
    }

    void free();
    void reallocate();
    
    value_type *elements;   // pointer to the first
    value_type *first_free; // pointer to the first free
    value_type *cap;        // pointer to one-past the end of raw unallocated space
    static std::allocator<value_type> alloc;
};

#include "vec.tpp"
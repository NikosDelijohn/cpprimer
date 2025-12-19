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

    // Copy control 
    vec(const vec &);
    vec(vec &&) noexcept;
    ~vec();
    vec& operator=(const vec &);
    vec& operator=(vec &&) noexcept;

    void push_back(const value_type&);
    void push_back(value_type&&);
    void pop_back();

    // Sizing members
    bool empty() const {return elements == first_free;}
    size_t size() const {return first_free - elements;}
    size_t capacity() const {return cap - elements;}
    
    void reserve(size_t);
    void resize(size_t);
    void resize(size_t, const value_type &);
    void clear()
    {
        while (elements != first_free)
            alloc.destroy(--first_free);
    }

    // Access members
    value_type& operator[](size_t index)
    {
        return *(elements + index);
    }
    const value_type& operator[](size_t index) const
    {
        return const_cast<vec*>(this)->operator[](index);
    }

    value_type& at(size_t index)
    {
        if (index >= size())
            throw std::out_of_range("Requested index (" + std::to_string (index) + ") is out of bounds!" );
        
        return (*this)[index];
    }
    const value_type& at(size_t index) const
    {
        return const_cast<vec*>(this)->at(index);
    }

    value_type& front() {return *elements; }
    const value_type& front() const {return const_cast<vec*>(this)->front(); }
    value_type& back() {return *(first_free - 1);}
    const value_type& back() const { return const_cast<vec*>(this)->back();}


    // Iterators
    value_type* begin() {return elements;}
    const value_type* begin() const {return const_cast<vec*>(this)->begin();}
    value_type* end()  {return first_free;} // not cap, cap is pointing to raw unconstructed memory
    const value_type* end() const {return const_cast<vec*>(this)->end();}
    const value_type* cbegin() const {return begin();}
    const value_type* cend() const {return end();}


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
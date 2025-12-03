#pragma once

#include <iostream>
#include <memory>
#include <string>

class strvec
{

    friend bool operator==(const strvec&, const strvec&);
    friend bool operator<(const strvec&, const strvec&);
    
public:

    strvec():
        elements(nullptr),
        first_free(nullptr),
        cap(nullptr)
    {}

    strvec(std::initializer_list<std::string> il) // ex1340
    {
        auto data = alloc_and_copy(il.begin(), il.end());
        
        elements = data.first;
        first_free = cap = data.second;
    }

    strvec(const strvec &);
    strvec(strvec &&) noexcept;
    ~strvec();
    strvec& operator=(const strvec &);
    strvec& operator=(strvec &&) noexcept;

    void push_back(const std::string&);

    size_t size() const {return first_free - elements;}
    size_t capacity() const {return cap - elements;}
    
    void reserve(size_t);
    void resize(size_t, const std::string & = "");

    std::string *begin() const {return elements;}
    std::string *end() const  {return first_free;} // not cap, cap is pointing to raw unconstructed memory

private:
    
    std::pair<std::string *, std::string *> 
    alloc_and_copy(const std::string*, const std::string *);

    void check_and_alloc()
    {
        if (size() == capacity())
            reallocate();
    }

    void free();
    void reallocate();
    
    std::string *elements;   // pointer to the first
    std::string *first_free; // pointer to the first free
    std::string *cap;        // pointer to one-past the end of raw unallocated space
    static std::allocator<std::string> alloc;
};


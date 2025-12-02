#include "string.hpp"
#include <cstring>
#include <iostream>
#include <algorithm>

#define NULL_TERM '\0'

std::allocator<char> string::alloc;

std::pair<char*, char*> 
string::copy_and_allocate(const char* b, const char* e)
{
    size_t sz = e - b;
    
    char* new_data = alloc.allocate(sz + 1);     // +1 for null terminator
    std::uninitialized_copy(b, e, new_data);

    new_data[sz] = NULL_TERM;

    return {new_data, new_data + sz};
}

void string::reallocate()
{
#ifndef NDEBUG
    std::cout << __func__ << ": Current string size(): " << size()
              << ". Current string capacity(): "<< capacity() << ". Reallocating!" << std::endl;
#endif

    size_t new_capacity = characters ? 2 * size() : 1;

    // +1 for null terminator
    char* new_data = alloc.allocate(new_capacity + 1);
    size_t sz = size();

    std::uninitialized_copy(characters, characters + sz, new_data);
    new_data[sz] = NULL_TERM; // place NULL right after the chars!

    free();

    characters = new_data;
    first_free = characters + sz;
    cap = characters + (new_capacity + 1);
}

void string::free()
{
    if (characters)
        alloc.deallocate(characters, cap - characters);
}

string::string(const char* cstr)
{
#ifndef NDEBUG
    std::cout << __func__ << " C_str Constructor Invoked. Building from (" << cstr << ")" << std::endl;
#endif

    size_t len = std::strlen(cstr);
    auto new_data = copy_and_allocate(cstr, cstr + len);

    characters = new_data.first;
    first_free = new_data.second;
    cap = characters + (len + 1);
}

string::string(const string &other)
{
#ifndef NDEBUG
    std::cout << __func__ << " Copy-Constructor Invoked" << std::endl;
#endif
    auto new_data = copy_and_allocate(other.begin(), other.end());

    characters = new_data.first;
    first_free = new_data.second;
    cap = characters + other.size() + 1;
}

string& string::operator=(const string &rhs)
{
#ifndef NDEBUG
    std::cout << __func__ << " Copy-Assignment operator (=) Invoked" << std::endl;
#endif

    if (this != &rhs)
    {
        auto new_data = copy_and_allocate(rhs.begin(), rhs.end());
        free();
        characters = new_data.first;
        first_free = new_data.second;
        cap = characters + rhs.size() + 1;
    }

    return *this;
}

string& string::operator=(string &&rhs) noexcept
{
#ifndef NDEBUG
    std::cout << __func__ << " Move-Assignment operator (=) Invoked" << std::endl;
#endif   

    if (this != &rhs)
    {
        free();

        characters = rhs.characters;
        first_free = rhs.first_free;
        cap = rhs.cap;

        rhs.characters = rhs.first_free = rhs.cap = nullptr;
    }

    return *this;
}

string::string(string &&other) noexcept :
    characters(other.characters),
    first_free(other.first_free),
    cap(other.cap)
{
#ifndef NDEBUG
    std::cout << __func__ << " Move Constructor Invoked" << std::endl;
#endif

    other.characters = other.first_free = other.cap = nullptr;
}

string::~string()
{
    free();
}

void string::reserve(size_t n)
{   
    if(n > capacity())
    {   
        auto new_data_beg = alloc.allocate(n + 1);
        auto new_data_end = new_data_beg + n + 1;

        auto src = characters;
        auto dst = new_data_beg;

        for (size_t i = 0; i <= size(); ++i) // <= to move also the NULL terminator
            *dst++ = std::move(*src++);

        free();

        characters = new_data_beg;
        first_free = dst - 1; // since we moved dst to the NULL terminator, we have to be carefull here and decrement by one
        cap = new_data_end;
    }
}

void string::push_back(const char &ch)
{
    check_and_allocate();
    *first_free++ = ch;
    *first_free = NULL_TERM;
}

void string::resize(size_t n, const char &ch)
{
    if (n > capacity())
        reserve(n);
    
    if (n > size())
    {
        while(n > size())
            push_back(ch);
    }
    else
    {
        while(n < size())
            --first_free;
        *first_free = NULL_TERM;
    }
}

bool operator==(const string &a, const string &b)
{
    if (a.size() != b.size())
        return false;

    return std::equal(a.begin(), a.end(), b.begin());
}

bool operator!=(const string &a, const string &b)
{
    return !(a == b);
}

// compile with -D STRING_TEST_MAIN for standalone usage.
#ifdef STRING_TEST_MAIN

void print_str(const string &str)
{
    for (size_t idx = 0u; idx < str.size(); ++idx)
    {
        std::cout << *(str.begin() + idx) << " " << std::ends;
    }
    std::cout << std::endl;
}

int main()
{
    string A("ABC");
    std::cout << A.size() << std::endl;

    print_str(A);

    A.resize(1);

    print_str(A);

    for(auto i = 0; i < 10; i++)
        A.push_back('B'+i);

    print_str(A);
    
    std::cout << "Length of string is: " << A.length() << std::endl;
    std::cout << "   Third element is: " << A.at(3) << std::endl;
    std::cout << "   Front element is: " << A.front() << std::endl;
    std::cout << "    Back element is: " << A.back() << std::endl;

    A.clear();

    print_str(A);


    string B("AAAA");
    std::cout << std::boolalpha << (B == "AAWA") << std::endl; // implicit ctor invocation

    return 0;
}
#endif
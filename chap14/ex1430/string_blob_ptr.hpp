#pragma once

#include <iostream>
#include <memory>
#include <vector>
#include <string>

#include "string_blob.hpp"


class String_Blob;

class String_Blob_Ptr
{
    friend String_Blob_Ptr operator+(size_t, const String_Blob_Ptr &);
    friend String_Blob_Ptr operator+(const String_Blob_Ptr &, size_t);
    friend String_Blob_Ptr operator-(size_t, const String_Blob_Ptr &);
    friend std::ptrdiff_t  operator-(const String_Blob_Ptr &lhs, const String_Blob_Ptr &rhs); 

    friend bool operator!=(const String_Blob_Ptr&, const String_Blob_Ptr&);
    friend bool operator<(const String_Blob_Ptr&, const String_Blob_Ptr&);

public:
    using size_type = std::vector<std::string>::size_type;

    String_Blob_Ptr();
    String_Blob_Ptr(String_Blob&, size_type sz = 0);

    std::string& operator[](size_t idx)
    {
        return (*check(idx, "Requested index out of bounds"))[idx];
    }

    const std::string& operator[](size_t idx) const
    {
        return (*check(idx, "Requested index out of bounds"))[idx];
    }

    String_Blob_Ptr& operator--();
    String_Blob_Ptr  operator--(int);
    String_Blob_Ptr& operator-=(size_t);

    String_Blob_Ptr& operator++();
    String_Blob_Ptr  operator++(int);
    String_Blob_Ptr& operator+=(size_t);

    std::string* operator->() const noexcept;
    std::string& operator*() const noexcept;


private:

    std::shared_ptr<std::vector<std::string>> 
        check(size_type idx, const std::string&) const;
    std::weak_ptr<std::vector<std::string>> wptr;
    size_type idx; 

};

inline bool operator!=(const String_Blob_Ptr& lhs, const String_Blob_Ptr& rhs) 
{
    return lhs.wptr.lock() != rhs.wptr.lock() || lhs.idx != rhs.idx;
    /*
    Two iterators pointing to the same container but 
    different positions are  not equal, even  if the 
    underlying data is the same.
    */
}

inline bool operator==(const String_Blob_Ptr& lhs, const String_Blob_Ptr& rhs) 
{
    return !(lhs != rhs);
}

inline bool operator<(const String_Blob_Ptr& lhs, const String_Blob_Ptr& rhs)
{   
    return lhs.wptr.lock() == rhs.wptr.lock() && lhs.idx < rhs.idx;
}

inline bool operator<=(const String_Blob_Ptr& lhs, const String_Blob_Ptr& rhs)
{
    return lhs == rhs || lhs < rhs;
}

inline bool operator>(const String_Blob_Ptr& lhs, const String_Blob_Ptr& rhs)
{
    return rhs < lhs;
}

inline bool operator>=(const String_Blob_Ptr& lhs, const String_Blob_Ptr& rhs)
{
    return !(lhs < rhs);
}
#pragma once

#include <iostream>
#include <memory>
#include <vector>
#include <string>

#include "string_blob.hpp"


class String_Blob;

class String_Blob_Ptr
{
    friend bool operator!=(const String_Blob_Ptr&, const String_Blob_Ptr&);
    friend bool operator==(const String_Blob_Ptr&, const String_Blob_Ptr&);

public:
    using size_type = std::vector<std::string>::size_type;

    String_Blob_Ptr();
    String_Blob_Ptr(String_Blob&, size_type sz = 0);

    std::string& dereference() const;

    String_Blob_Ptr& increment();

private:

    std::shared_ptr<std::vector<std::string>> 
        check(size_type idx, const std::string&) const;
    std::weak_ptr<std::vector<std::string>> wptr;
    size_type idx; 

};

inline bool operator!=(const String_Blob_Ptr& lhs, const String_Blob_Ptr& rhs) 
{
    return lhs.wptr.lock() != rhs.wptr.lock() || lhs.idx != rhs.idx;
}

inline bool operator==(const String_Blob_Ptr& lhs, const String_Blob_Ptr& rhs) 
{
    return !(lhs != rhs);
}
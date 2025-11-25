#pragma once

#include <iostream>
#include <memory>
#include <vector>
#include <string>

#include "string_blob.hpp"


class String_Blob;

class Const_String_Blob_Ptr
{

public:
    using size_type = std::vector<std::string>::size_type;

    Const_String_Blob_Ptr();
    Const_String_Blob_Ptr(const String_Blob&, size_type sz = 0);

    const std::string& dereference() const;

    Const_String_Blob_Ptr& increment();

private:

    std::shared_ptr<std::vector<std::string>> 
        check(size_type idx, const std::string&) const;
    std::weak_ptr<std::vector<std::string>> wptr;
    size_type idx; 

};
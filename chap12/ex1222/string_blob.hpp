#pragma once

#include <iostream>
#include <memory>
#include <vector>
#include <string>

class String_Blob_Ptr;
class Const_String_Blob_Ptr;

class String_Blob
{
    friend class Const_String_Blob_Ptr;
    friend class String_Blob_Ptr;
    
public:
    using size_type = std::vector<std::string>::size_type;

    String_Blob();
    String_Blob(std::initializer_list<std::string>);

    String_Blob_Ptr begin();
    String_Blob_Ptr end();

    std::string& front();
    const std::string& front() const;
    std::string& back();
    const std::string& back() const;

    void push_back(const std::string &);
    void pop_back();

    long get_uses() { return data.use_count(); }

private:
    void check(size_type, const std::string &) const;
    std::shared_ptr<std::vector<std::string>> data;

};
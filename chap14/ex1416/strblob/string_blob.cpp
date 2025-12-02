#include "string_blob.hpp"
#include <algorithm>

String_Blob::String_Blob(): 
    data(std::make_shared<std::vector<std::string>>())
{}

String_Blob::String_Blob(std::initializer_list<std::string> strings):
    data(std::make_shared<std::vector<std::string>>(strings))
{}

String_Blob::String_Blob(const String_Blob &other):
    data(std::make_shared<std::vector<std::string>>(*other.data)) // deep copy
{}

String_Blob& String_Blob::operator=(const String_Blob &other)
{
    data = std::make_shared<std::vector<std::string>>(*other.data);
    return *this;
}

inline
void String_Blob::check(size_type idx, const std::string &str) const
{
    if(idx >= data->size())
    {
        throw std::out_of_range(str);
    }
}

inline
const std::string& String_Blob::front() const
{
    check(0, "There is no front element");
    return data->front();
} 

inline
const std::string& String_Blob::back() const
{
    check(data->size() - 1, "There is no back element");
    return data->back();
}

inline
std::string& String_Blob::front()
{
    check(0, "There is no front element");
    return  data->front();
}

inline
std::string& String_Blob::back()
{
    check(data->size() - 1, "There is no back element");
    return data->back();
}

void String_Blob::pop_back()
{
    check(data->size() - 1, "Nothing to pop!");
    data->pop_back();
}

void String_Blob::push_back(const std::string & str)
{
    data->push_back(str);
}

String_Blob_Ptr String_Blob::begin()
{
    return String_Blob_Ptr(*this);
}

String_Blob_Ptr String_Blob::end()
{
    return String_Blob_Ptr(*this, data->size());
}

bool operator==(const String_Blob &a, const String_Blob &b)
{
    if (a.data->size() != b.data->size())
        return false;
    
    return std::equal(a.data->begin(), a.data->end(), b.data->begin());
}

bool operator!=(const String_Blob &a, const String_Blob &b)
{
    return !(a == b);
}
#include "string_blob_ptr.hpp"

String_Blob_Ptr::String_Blob_Ptr(): idx(0) {}

String_Blob_Ptr::String_Blob_Ptr(String_Blob &ref, size_type sz):
    wptr(ref.data),
    idx(sz)
{}

std::shared_ptr<std::vector<std::string>>
String_Blob_Ptr::check(size_type idx, const std::string& msg) const
{
    auto sh_ptr = wptr.lock();
    
    if (!sh_ptr)
        throw std::runtime_error("String_Blob_Ptr is unbound!");

    if (idx >= sh_ptr->size())
        throw std::out_of_range(msg);
    
    return sh_ptr;
     
}

std::string& String_Blob_Ptr::dereference() const
{
    auto sh_ptr = check(idx, "Dereference past the end");
    return (*sh_ptr)[idx];
}

String_Blob_Ptr& String_Blob_Ptr::increment()
{
    auto sh_ptr = check(idx, "Index is invalid! Can't increment!");
    ++idx;
    return *this;
}

#include "const_string_blob_ptr.hpp"

Const_String_Blob_Ptr::Const_String_Blob_Ptr(): idx(0) {}

Const_String_Blob_Ptr::Const_String_Blob_Ptr(const String_Blob &ref, size_type sz):
    wptr(ref.data),
    idx(sz)
{}

std::shared_ptr<std::vector<std::string>>
Const_String_Blob_Ptr::check(size_type idx, const std::string& msg) const
{
    auto sh_ptr = wptr.lock();
    
    if (!sh_ptr)
        throw std::runtime_error("Const_String_Blob_Ptr is unbound!");

    if (idx >= sh_ptr->size())
        throw std::out_of_range(msg);
    
    return sh_ptr;
     
}

const std::string& Const_String_Blob_Ptr::dereference() const
{
    auto sh_ptr = check(idx, "Dereference past the end");
    return (*sh_ptr)[idx];
}

Const_String_Blob_Ptr& Const_String_Blob_Ptr::increment()
{
    auto sh_ptr = check(idx, "Index is invalid! Can't increment!");
    ++idx;
    return *this;
}

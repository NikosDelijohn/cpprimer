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

String_Blob_Ptr& String_Blob_Ptr::operator++()
{

    auto sp = check(0, "Iterator unbound");

    if (idx >= sp->size())
        throw std::out_of_range("Increment past end iterator");

    ++idx;
    return *this;
}

String_Blob_Ptr String_Blob_Ptr::operator++(int)
{
    String_Blob_Ptr ret = *this;
    ++*this;
    return ret;
}

String_Blob_Ptr& String_Blob_Ptr::operator+=(size_t n)
{
    auto sp = check(0, "Iterator unbound");

    if (n > sp->size() - idx)
        throw std::out_of_range("Incrementing past the end()");

    idx += n;
    return *this;
}

String_Blob_Ptr& String_Blob_Ptr::operator--()
{
    if (idx == 0)
        throw std::out_of_range("Iterator is already at index 0. Decrementing will go out of bounds");
    
    --idx;
    return *this;
}

String_Blob_Ptr String_Blob_Ptr::operator--(int)
{
    if (idx == 0)
        throw std::out_of_range("Iterator is already at index 0. Decrementing will go out of bounds");

    String_Blob_Ptr ret = *this;
    --*this;
    return ret;
}

String_Blob_Ptr& String_Blob_Ptr::operator-=(size_t n)
{

    auto sp = check(0, "Iterator unbound");

    if (n > idx)
        throw std::out_of_range("Decrementing before begin()");

    idx -= n;
    return *this;
}

String_Blob_Ptr operator+(size_t n, const String_Blob_Ptr &ptr)
{
    return (String_Blob_Ptr(ptr) += n);
}

String_Blob_Ptr operator+(const String_Blob_Ptr &ptr, size_t n)
{
    return (String_Blob_Ptr(ptr) += n);
}

std::ptrdiff_t operator-(const String_Blob_Ptr &lhs, const String_Blob_Ptr &rhs)
{
    return static_cast<std::ptrdiff_t>(lhs.idx) - static_cast<std::ptrdiff_t>(rhs.idx);
}

std::string& String_Blob_Ptr::operator*() const noexcept
{
    auto ptr = check(idx, "Unbound pointer!");
    return (*ptr)[idx];
}

std::string* String_Blob_Ptr::operator->() const noexcept
{
    return & this->operator*();
}

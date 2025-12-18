#pragma once

#include <memory>
#include <vector>
#include <string>
#include "blob.hpp"

template <typename T> bool operator==(const BlobPtr<T>&, const BlobPtr<T>&);
template <typename T> bool operator!=(const BlobPtr<T>&, const BlobPtr<T>&);

template <typename Element>
class BlobPtr
{
    friend bool operator==<Element>(const BlobPtr&, const BlobPtr&);
    friend bool operator!=<Element>(const BlobPtr&, const BlobPtr&);

public:
    
    using value_type = Element;
    using size_type = typename std::vector<Element>::size_type;


    BlobPtr(Blob<Element>& blob, size_type idx = 0u):
        current_index(idx), data(blob.data)
    {}
    ~BlobPtr() = default;

    value_type& operator*()
    {
        auto sh_ptr = check(current_index, "Pointer at index " + std::to_string(current_index) + " is out of bounds!");
        return sh_ptr->at(current_index);
    }

    BlobPtr& operator++()
    {
        current_index++;
        return *this;
    }

    BlobPtr operator++(int)
    {
        BlobPtr retval = *this;
        ++*this;
        return retval;    
    }

    BlobPtr& operator--()
    {
        --current_index;
        return *this;
    }

    BlobPtr operator--(int)
    {
        BlobPtr retval = *this;
        --*this;
        return retval;
    }

private:
    
    std::shared_ptr<std::vector<value_type>> check(size_type idx, const std::string &errmsg) const
    {
        auto ptr = data.lock();

        if (!ptr)
            throw std::runtime_error("Unbound weak pointer!");
        
        if (idx >= ptr->size())
            throw std::out_of_range(errmsg);

        return ptr;
    }

    size_type current_index;
    std::weak_ptr<std::vector<value_type>> data;

};

template <typename Element>
bool operator==(const BlobPtr<Element>& lhs, const BlobPtr<Element>& rhs)
{
    auto lp = lhs.data.lock();
    auto rp = rhs.data.lock();

    if (!lp || !rp)
        return false; 

    return lp == rp && lhs.current_index == rhs.current_index;
}

template <typename Element>
bool operator!=(const BlobPtr<Element>& lhs, const BlobPtr<Element>& rhs)
{
 return !(lhs == rhs);
}
#pragma once

#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <initializer_list>

template <typename Element> class BlobPtr;

template <typename Element>
class Blob
{
    friend class BlobPtr<Element>;

public:

    using value_type = Element;
    using size_type =  typename std::vector<Element>::size_type;

    Blob():
        data(std::make_shared<std::vector<value_type>>())
    {}
    
    Blob(std::initializer_list<value_type> il):
        data(std::make_shared<std::vector<value_type>>(il))
    {}

    template <typename Iterator>
    Blob (Iterator a, Iterator b):
        data(std::make_shared<std::vector<value_type>>(a, b))
    {}
    
    ~Blob() = default;

    size_type size() const {return data->size();}
    void push_back(const value_type& element){data->push_back(element);}
    void push_back(value_type&& element){data->push_back(std::move(element));}
    value_type pop_back() 
    {
        check(0, "Nothing to pop!");
        value_type retval = data->back();
        data->pop_back();

        return retval;
    }

    value_type& operator[](const size_type& idx)
    {
        check(idx, "Index is out of bounds!");
        return data->at(idx);
    }

    const value_type& operator[](const size_type& idx) const
    {
        return (*data)[idx];
    }

    value_type& front() { check(0, "Blob is empty!"); return data->at(0);}
    const value_type& front() const { check(0, "Blob is empty!"); return data->at(0);}

    value_type& back() {check(0, "Blob is empty!"); return data->at(data->size()-1);}
    const value_type& back() const {check(0, "Blob is empty!"); return data->at(data->size()-1);}


    BlobPtr<value_type> begin() {return BlobPtr<value_type>(*this);}
    BlobPtr<value_type> end() {return BlobPtr<value_type>(*this, data->size());}

private:

    void check(size_type idx, const std::string &errmsg)
    {
        if(idx >= data->size())
            throw std::out_of_range(errmsg);
    }
    std::shared_ptr<std::vector<value_type>> data;

};
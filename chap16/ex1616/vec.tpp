#include <memory>
#include <functional>

template <typename Element>
std::allocator<Element> vec<Element>::alloc;

template <typename Element> 
std::pair<Element*, Element*> 
vec<Element>::alloc_and_copy(const Element* start, const Element *end)
{
    Element* new_data_begin = alloc.allocate(end - start);
    Element* new_data_end   = std::uninitialized_copy(start, end, new_data_begin);

    return {new_data_begin, new_data_end};
}

template <typename Element> 
void vec<Element>::free()
{
    if (!elements)
        return;

    while (first_free != elements)
        alloc.destroy(--first_free);
    
    alloc.deallocate(elements, cap - elements);

    elements = first_free = cap = nullptr;
}

template <typename Element> 
void vec<Element>::reallocate()
{
  
    size_t new_size = (elements) ? 2*capacity() : 1;

    Element* new_begin = alloc.allocate(new_size);
    Element* new_end   = new_begin + new_size;

    // from src to dest
    Element* src = elements;
    Element* dst = new_begin;

    try 
    {
        for (Element* p = elements; p != first_free; ++p)
            alloc.construct(dst++, std::move(*p));
    }
    catch (...)
    {
        while (dst != new_begin)
            alloc.destroy(--dst);
        alloc.deallocate(new_begin, new_end - new_begin);
        throw;
    }

    // purge current resources and release the occupied memory
    free(); 

    // update pointers to the new margins
    elements = new_begin;
    first_free = dst;
    cap = new_end;

}

// COPY CONTROL MEMBERS

template <typename Element> 
vec<Element>::vec(const vec& other)
{
    auto new_margins = alloc_and_copy(other.elements, other.first_free);

    elements = new_margins.first;
    first_free = cap = new_margins.second;
}

template <typename Element> 
vec<Element>::vec(vec&& other) noexcept
{

    elements = other.elements;
    first_free = other.first_free;
    cap = other.cap;

    other.elements = nullptr;
    other.first_free = nullptr;
    other.cap = nullptr;
}

template <typename Element> 
vec<Element>::~vec()
{
    free();
}

template <typename Element>
vec<Element>& vec<Element>::operator=(const vec& rhs)
{
    if (this != &rhs)
    {
        // 1) acquire new resources first (may throw)
        auto new_margins = alloc_and_copy(rhs.elements, rhs.first_free);

        // 2) commit only after success
        free();

        elements   = new_margins.first;
        first_free = new_margins.second;
        cap        = new_margins.second;
    }
    return *this;
}

template <typename Element>
vec<Element>& vec<Element>::operator=(vec&& rhs) noexcept
{
    if (this != &rhs)
    {
        free();
        elements = rhs.elements;
        first_free = rhs.first_free;
        cap = rhs.cap;

        rhs.elements = nullptr;
        rhs.first_free = nullptr;
        rhs.cap = nullptr;
    }
    return *this;
}

template <typename Element>
void vec<Element>::push_back(const Element& element)
{
    check_and_alloc();
    alloc.construct(first_free++, element);

}

#include <iostream>
#include <cstring>
#include <string>

template <typename T>
int compare(const T& a, const T& b) 
{
    std::cout << "Template\n";
    return a < b;
}

// ------------------------------------------------------------
// Overload for C-style string literals and fixed char arrays
// ------------------------------------------------------------
// Compares two character arrays lexicographically using strcmp.
//
// Why this overload exists:
// - String literals have type const char[N], not const char*.
// - Taking the parameters as references to arrays prevents
//   array-to-pointer decay.
// - The array sizes (N and M) are preserved at compile time.
// - This avoids comparing pointer addresses, which would be wrong.
//
// This overload is preferred over the generic template when
// string literals or fixed-size char arrays are passed.
//
template <size_t N, size_t M>
int compare(const char (&a)[N], const char (&b)[M])
{
    std::cout << "Overloaded\n";
    return std::strcmp(a,b);
}

// ------------------------------------------------------------
// Explicit specialization of the primary compare<T> template
// for const char*
//
// This specialization is selected ONLY when the primary
// template would be instantiated with T = const char*.
//
// Purpose:
// - Prevents pointer-address comparison (a < b) for C-style
//   strings, which would be semantically incorrect.
// - Replaces it with a lexicographical comparison using strcmp.
//
// Parameter types explained:
// - const char* const&
//   └─ reference to a const pointer to const char
//
//   * outer const  : the pointer itself cannot be modified
//   * inner const  : the pointed-to characters cannot be modified
//   * reference    : avoids copying the pointer and matches
//                    the primary template’s signature pattern
//
// Important notes:
// - This specialization handles ONLY const char* arguments
//   (e.g., pointers, not string literals directly).
// - String literals ("abc") still prefer the array-reference
//   overload (const char(&)[N]) because it is a better match.
// - This is template specialization, not overload resolution.
//
template<>
int compare(const char* const& a, const char* const& b)
{   
    std::cout << "Specialized\n";
    return std::strcmp(a,b);
}


int main()
{
    compare(std::string("a"), std::string("b"));

    char arr1[] = "Hello", arr2[] = "My Friend";
    compare(arr1, arr2);

    auto cstr1 = "This is", cstr2 = "Template Specialization";
    compare(cstr1, cstr2);


    return EXIT_SUCCESS;
}
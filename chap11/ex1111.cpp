#include <iostream>
#include <set>
#include "../sales_data.hpp"

bool compare_isbn(const Sales_data &lhs, const Sales_data &rhs)
{
    return lhs.isbn() < rhs.isbn();
}

using CompareFnPtr = bool(*)(const Sales_data&, const Sales_data&);

int main()
{
    std::multiset<Sales_data, CompareFnPtr> bookstore(compare_isbn);

    return EXIT_SUCCESS;
}
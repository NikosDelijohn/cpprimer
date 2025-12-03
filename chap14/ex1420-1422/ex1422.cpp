#include "sales_data.hpp"
#include <fstream>


int main()
{
    std::ifstream input("Sales_data-input.txt");
    
    Sales_data A(input);

    std::cout << A << std::endl;

    //A = std::string("A Brave new World!");

    // operator= expects a std::string&, which is a non-const lvalue reference.
    // Therefore it cannot bind to an rvalue temporary such as std::string("A Brave New World!").
    // This makes that operator ineligible.
    //
    // Next, overload resolution considers the synthesized copy-assignment operator:
    //      Sales_data& operator=(const Sales_data&);
    //
    // To call that operator, the compiler must create a temporary Sales_data object
    // from the right-hand-side string. This is possible because the constructor
    //      Sales_data(const std::string&)
    // is not explicit, so implicit conversion is allowed.
    //
    // Therefore the compiler does:
    //
    //      Sales_data tmp("A Brave New World!");
    //      A = tmp;   // copy assignment
    //
    // As a result, the book_isbn is replaced AND the items_sold and total_revenue
    // are reset to the values set by the converting constructor (usually zeros).
    //
    // The string-assignment operator is never invoked.

    // Better to make the assignment operator to accept const std::string& 
    // in order to accept both rvalues and lvalues -OR- make the single ctors
    // of the class explicit!

    std::string new_title = "A Brave New World!";
    A = new_title;

    // After making the ctors explicit, this no longer works and its safe.

    std::cout << A << std::endl;

    return EXIT_SUCCESS;
}
#include "sales_data.hpp"
#include <fstream>


int main()
{
    std::ifstream input("Sales_data-input.txt");
    
    Sales_data A(input);
    Sales_data B(input);

    std::cout << A << std::endl << B << std::endl;
    // >> oper needs sanitization (sstreams -> line word processing)

    A += B; 

    /* 
    *this = *this + other; we create an extra copy when we compare with the more idiomatic, approach of + oper using +=
    */

    std::cout << A << std::endl;

    return EXIT_SUCCESS;
}
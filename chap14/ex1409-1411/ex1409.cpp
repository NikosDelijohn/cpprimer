#include "sales_data.hpp"
#include <fstream>

int main()
{
    std::ifstream input("Sales_data-input.txt");
    
    Sales_data temp;
    while(input >> temp)
        std::cout << temp << std::endl;
    
    // >> oper needs sanitization (sstreams -> line word processing)
    return EXIT_SUCCESS;
}
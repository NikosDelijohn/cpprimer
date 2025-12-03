#include "sales_data.hpp"
#include <fstream>


int main()
{
    std::ifstream input("Sales_data-input.txt");
    
    Sales_data A(input);
    Sales_data B(input);

    A = std::string("Pepega");
    
    std::cout << A << std::endl;

    return EXIT_SUCCESS;
}
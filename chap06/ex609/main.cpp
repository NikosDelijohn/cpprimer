#include <iostream>
#include "ex609.hpp"

int main()
{
    unsigned number;

    std::cout << "Factorial of: ";
    std::cin >> number;

    std::cout << " = " << factorial(number) << std::endl;

}
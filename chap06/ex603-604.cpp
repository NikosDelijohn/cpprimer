#include <iostream>

unsigned long int factorial(unsigned val)
{
    if (val == 0)
        return 1UL;
    else if (val == 2 || val == 1)
        return val;
    else
        return val * factorial(val - 1UL);
}

int main()
{

    unsigned number;

    std::cout << "Factorial of: ";
    std::cin >> number;

    std::cout << " = " << factorial(number) << std::endl;

}
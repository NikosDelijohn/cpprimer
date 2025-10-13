#include <iostream>

int number = 123;

int main()
{

    int number = 321;
    
    std::cout << "Local number is: " << number << std::endl
              << "However global is: " << ::number << std::endl;

    int new_number = ::number;

    std::cout << new_number << std::endl;

    return 0;
 
}
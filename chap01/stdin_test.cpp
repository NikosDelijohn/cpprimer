#include <iostream>

int main()
{

    int number; 

    // test fails when EOF or non-integer is given
    // EOF for Unix systems is CTRL+D
    while (std::cin >> number)
    {
        std::cout << number << std::endl;
    }

    return 0;
}
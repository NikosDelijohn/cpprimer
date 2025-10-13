#include <iostream>
/*
Write a program that performs muiltiplication of 2 numbers
given by the user from stdin and displays the result to stdout;
*/
int main()
{
    std::cout << "Give me 2 numbers to multiply" << std::endl;
    
    int numb_a, numb_b = 0;
    std::cin >> numb_a >> numb_b;

    std::cout << numb_a << " x " << numb_b << " = " << numb_a * numb_b << std::endl;

    return 0;
}
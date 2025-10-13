#include <iostream>
/*
Split the output to multiple lines on stdout for ex.1.4
*/
int main()
{
    std::cout << "Give me 2 numbers to multiply" << std::endl;
    
    int numb_a, numb_b = 0;
    std::cin >> numb_a >> numb_b;

    std::cout << numb_a << std::endl <<  " times " << std::endl
              << numb_b << std::endl << " equals " << std::endl 
              <<  numb_a * numb_b << std::endl;

    return 0;
}
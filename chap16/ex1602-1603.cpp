#include <iostream>

template <typename T>
const T& compare(const T& a, const T& b)
{
    if (a < b)
        return a;
    
    if (b < a)
        return b;
    
    return a;
}

struct no_less_oper
{
    int a;
};

int main()
{
  
    std::cout << compare(1,2) << std::endl;

    //std::cout << compare(no_less_oper{1}, no_less_oper{2}) << std::endl; // Wrong, no < operator for type no_less_oper

    /*
    ex1602.cpp:6:11: error: no match for ‘operator<’ (operand types are ‘const no_less_oper’ and ‘const no_less_oper’)
    6 |     if (a < b)
      |         ~~^~~
    ex1602.cpp:9:11: error: no match for ‘operator<’ (operand types are ‘const no_less_oper’ and ‘const no_less_oper’)
        9 |     if (b < a)
    */

    return EXIT_SUCCESS;
}
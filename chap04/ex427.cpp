#include <iostream>
#include "../help.hpp"

int main()
{
    unsigned long ul1 = 3, ul2 = 7;

    auto res1 = ul1 & ul2; // res 3
    auto res2 = ul1 | ul2; // res 7
    auto res3 = ul1 && ul2; // res true (1)
    auto res4 = ul1 || ul2; // res true (1)
    
    std::cout << res1 << ' ' << res2 << ' ' << res3 << ' ' << res4 << std::endl;
    
    return 0;
}
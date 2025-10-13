#include <iostream>

int main()
{

    unsigned char tiny = 257;
    signed char s_tiny = 128;

    // expect 1 
    std::cout << (int) tiny << std::endl;
    // expect -128 (overflow to sign bit)
    std::cout << (int) s_tiny << std::endl;

    return 0;
}
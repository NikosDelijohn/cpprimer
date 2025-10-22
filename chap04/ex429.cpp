#include <iostream>

int main()
{
    int x[10]; int *p=x;

    std::cout << sizeof(x)/sizeof(*x) << std::endl; // 10*4/4 = 10
    std::cout << sizeof(p)/sizeof(*p) << std::endl; // 8/4 = 2

    // my OS is 64-bit, hence ptrs are 64-bits -> 8 bytes
    
    return 0;
}
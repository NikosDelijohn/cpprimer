#include <iostream>

int main()
{

    int ival = 1024;
    int &ref_val = ival;

    std::cout << ival << std::endl; // 1024
    ref_val = 2;
    std::cout << ival << std::endl; // 2

    int &ref_val2 = ref_val;
    ref_val2 = 3; 
    std::cout << ival << std::endl; // 3

    int i = ref_val2;
    i = 4;
    std::cout << ival << std::endl; // 3

    return 0;
}
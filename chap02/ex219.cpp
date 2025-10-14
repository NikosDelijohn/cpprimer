#include <iostream>

int main()
{

    int i = 42;
    int *pi = &i;
    *pi = *pi * *pi; // 42 x 42, modifies variable i

    std::cout << (*pi == i) << std::endl; // expect 1

    return 0;
}
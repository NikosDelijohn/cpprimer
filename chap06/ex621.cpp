#include <iostream>

int larger_of(int a, const int* b)
{
    int retval;

    if (a > *b)
        retval = a;
    else
        retval = *b;
    
    return retval;
}

int main()
{
    int a = 1, b = 2;

    int c = larger_of(a, &b);

    std::cout << c << std::endl;

    return 0;
}
#include <iostream>

int main()
{

    int i; double d;

    d = i = 3.5;
    std::cout << ((d == 3.0) && (i == 3)) << std::endl;

    i = d = 3.5;
    std::cout << ((d == 3.5) && (i == 3)) << std::endl;

    return 0;
}
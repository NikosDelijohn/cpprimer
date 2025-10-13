#include <iostream>

int main()
{
    int i = 0, &r1 = i;
    double d = 0, &r2 = d;

    r2 = 3.14159; // ok d is set to 3.14159
    r2 = r1; // ok r2 -> d is set to 0
    i = r2; // ok i = d. i is set to 0
    r1 = d; // ok i = d

    std::cout << "i, &r1, d, &r2 = " << i 
              << ", " << r1 << ", "
              << d << ", " 
              << r2 << "." << std::endl;

    return 0;
}
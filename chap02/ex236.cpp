#include <iostream>

int main()
{
    int a = 3, b = 4;
    decltype(a) c = a; // c is int
    decltype((b)) d = a; // d is int &

    ++c;
    ++d;

    // a = 4
    // b = 4
    // c = 4
    // d = 4

    std::cout << a << b << c << d << std::endl;

    return 0;
}
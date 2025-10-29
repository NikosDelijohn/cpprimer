#include <iostream>
#include <cassert>

void f()
{
    std::cout << __func__ << "()" << std::endl;
}

void f(int a)
{
    std::cout << __func__ << "(int)" << std::endl;
}

void f(int a, int b)
{
    std::cout << __func__ << "(int, int)" << std::endl;
}

void f(double a, double b = 3.14)
{
    std::cout << __func__ << "(double, double)" << std::endl;
}

int main()
{
    // f(2.56, 42); // ambiguous!!
    f(42);
    f(42,0);
    f(2.56, 3.14);

    return 0;
}
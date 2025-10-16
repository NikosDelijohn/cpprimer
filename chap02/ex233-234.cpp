#include <iostream>

int main()
{

    int i = 0, &r = i;
    auto a = r;
    const int ci = i, &cr = ci;
    auto b = ci;
    auto c = cr;
    auto d = &i;
    auto e = &ci;

    const auto f = ci;
    auto &g = ci;

    std::cout << "<a,b,c> = <" << a << ", " << b << ", " << c <<">" << std::endl;

    a = 42; // ok, a is int
    b = 42; // ok, b is int
    c = 42; // ok, c is int

    std::cout << "<a,b,c> = <" << a << ", " << b << ", " << c <<">" << std::endl;

    //d = 42; // not ok! d is an int * 
    //e = 42; // not ok! e is a const int * . Top-level const is not ignored on the initializer
    //g = 42; // not ok! g is a const int & . Top-level const is not ignored on the initializer
    
    return 0;
}
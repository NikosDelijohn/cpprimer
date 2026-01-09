#include <iostream>
#include <type_traits>

int main()
{
    int x = 0;

    typedef int&  L;   // L is int&
    typedef int&& R;   // R is int&&

    // 1) L&  -> int& & -> collapses to int &
    L& a = x;

    // 2) L&& -> int& && -> int &
    L&& b = x;

    // 3) R&  -> int&& & -> int &
    R& c = x;

    // 4) R&& -> int&& && -> int &&
    R&& d = 5;

    std::cout << std::boolalpha;

    std::cout << "a is lvalue ref: "
              << std::is_lvalue_reference<decltype(a)>::value << '\n';

    std::cout << "b is lvalue ref: "
              << std::is_lvalue_reference<decltype(b)>::value << '\n';

    std::cout << "c is lvalue ref: "
              << std::is_lvalue_reference<decltype(c)>::value << '\n';

    std::cout << "d is rvalue ref: "
              << std::is_rvalue_reference<decltype(d)>::value << '\n';
}
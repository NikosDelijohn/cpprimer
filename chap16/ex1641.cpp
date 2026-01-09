#include <iostream>

/*
    the -> decltype(a+b) part:
    
    Applies the usual arithmetic conversions (for built-in types)

    short + short → int
    int + double → double
    long + int → long

    Or, for class types:
        Calls the selected operator+
        Uses whatever type that operator returns

    At this point, the language has already decided that this the type that can represent the sum.

*/

template <typename A, typename B>
auto general_sum(const A& a, const B& b) -> decltype(a + b)
{
    return a + b;
}

int main()
{
    auto x = general_sum(1, 2);        // int
    auto y = general_sum(1, 2.5);      // double
    auto z = general_sum(short{1}, 2); // int

    std::cout << x << ' ' << y << ' ' << z << '\n';
}
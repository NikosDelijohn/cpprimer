#include <iostream>
#include <utility>   // std::move

// (1) Non-const lvalue reference
// Binds ONLY to non-const lvalues
void h(int& x)
{
    std::cout << "h(int&)\n";
}

// (2) Const lvalue reference
// Binds to lvalues AND rvalues
void h(const int& x)
{
    std::cout << "h(const int&)\n";
}

// (3) Rvalue reference
// Binds ONLY to rvalues
void h(int&& x)
{
    std::cout << "h(int&&)\n";
}

// ------------------------------------------------------------
// Template using a forwarding (universal) reference
// ------------------------------------------------------------
template <typename T>
void f(T&& x)
{
    // IMPORTANT RULE:
    // Even if x has type int&&, the *expression* x is an LVALUE
    // because it is a named variable.

    // Therefore this call ALWAYS treats x as an lvalue.
    h(x);

    // std::move(x) casts x to an rvalue expression.
    // This does NOT move anything by itself.
    // It only changes the value category for overload resolution.
    h(std::move(x));
}

int main()
{
    int i = 0;
    const int ci = 0;

    // --------------------------------------------------------
    // Case 1: pass a non-const lvalue
    // --------------------------------------------------------
    std::cout << "Calling f(i):\n";

    // Deduction:
    //   T = int&
    //   Parameter type: T&& -> int& && -> int& 
    //
    // Inside f:
    //   x is an lvalue reference to i
    f(i);

    // Expected binding:
    //   h(x)           -> h(int&)   (x is lvalue, non-const)
    //   h(std::move(x)) -> h(int&&) (forced rvalue)

    // --------------------------------------------------------
    // Case 2: pass a const lvalue
    // --------------------------------------------------------
    std::cout << "\nCalling f(ci):\n";

    // Deduction:
    //   T = const int&
    //   Parameter type: T&& -> const int& && -> const int&
    //
    // Inside f:
    //   x is a const lvalue reference
    f(ci);

    // Expected binding:
    //   h(x)           -> h(const int&)  (cannot bind to int&)
    //   h(std::move(x)) -> h(const int&) (no h(const int&&) exists)

    // --------------------------------------------------------
    // Case 3: pass an rvalue
    // --------------------------------------------------------
    std::cout << "\nCalling f(42):\n";

    // Deduction:
    //   T = int
    //   Parameter type: T&& -> int&&
    //
    // Inside f:
    //   x is an rvalue reference, BUT the expression x is an lvalue
    f(42);

    // Expected binding:
    //   h(x)           -> h(int&)   (named rvalue ref is lvalue)
    //   h(std::move(x)) -> h(int&&) (explicit rvalue)

    return 0;
}
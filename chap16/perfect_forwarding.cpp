// perfect_forwarding_variadic.cpp
// Perfect forwarding with parameter packs (ellipsis)

#include <iostream>
#include <utility>

// A type with visible copy / move
struct Obj {
    Obj() { std::cout << "Obj()\n"; }
    Obj(const Obj&) { std::cout << "Obj(const Obj&)\n"; }
    Obj(Obj&&) { std::cout << "Obj(Obj&&)\n"; }
};

// Target function with multiple parameters
void sink(const Obj& a, Obj&& b)
{
    std::cout << "sink(const Obj&, Obj&&)\n";
}

// Perfect-forwarding wrapper
template <typename... Args>
void wrapper(Args&&... args)
{
    // Args&&... are forwarding references.
    // Each Args follows reference-collapsing rules independently:
    //
    // If an argument is an lvalue of type X:
    //    Args = X&   -> Args&& collapses to X&
    //
    // If an argument is an rvalue of type X:
    //    Args = X    -> Args&& is X&&
    //
    // std::forward<Args>(args)... preserves each value category.

    sink(std::forward<Args>(args)...);
}

int main()
{
    Obj x;

    std::cout << "\n--- Mixed call (lvalue, rvalue) ---\n";
    wrapper(x, Obj{});
    // Args deduced as: (Obj&, Obj)
    // Forwarded as:    (Obj&, Obj&&)
    // Matches sink(const Obj&, Obj&&)

    std::cout << "\n--- Both lvalues ---\n";
    wrapper(x, x);
    // Args deduced as: (Obj&, Obj&)
    // Forwarded as:    (Obj&, Obj&)
    // Would fail to bind to sink (needs rvalue for second)

    std::cout << "\n--- Both rvalues ---\n";
    wrapper(Obj{}, Obj{});
    // Args deduced as: (Obj, Obj)
    // Forwarded as:    (Obj&&, Obj&&)
}

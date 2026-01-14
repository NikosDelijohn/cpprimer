#include <iostream>

/*
    The ellipsis '...' in variadic templates has three distinct roles:

    1) Declaration of a template parameter pack
       template <typename... Args>
       Means: Args is a pack of zero or more types: <T1, T2, T3, ...>

    2) Declaration of a function parameter pack
       void func(Args... args)
       Means: args is a pack of values whose types are Args.
       The pattern before '...' (here: Args) is repeated for each element.

    3) Pack expansion in expressions
       func(args...)
       Means: expand the pack into a comma-separated list of expressions.

    The general rule is:
       pattern...   -> repeat 'pattern' once for each element of the pack.
*/

// 1) Simple variadic function template
template <typename... Args>              // Args = <T1, T2, T3, ...>
void print_count(Args... args)           // args = (arg1, arg2, arg3, ...)
{
    // sizeof...(Args)  : number of types in the pack
    // sizeof...(args)  : number of function arguments
    std::cout << "Number of arguments = " << sizeof...(Args) << '\n';
}

// 2) Variadic class template
template <typename... Ts>                // Ts is a pack of template type parameters
struct TypeList
{
    static constexpr std::size_t size = sizeof...(Ts); // compile-time pack size
};

// 3) Recursive variadic function using pack expansion

// Base case: one argument, no pack
template <typename T>
void print(const T& t)
{
    std::cout << t << '\n';
}

// Recursive case: one fixed argument + a parameter pack
template <typename T, typename... Rest>  // Rest = <R1, R2, R3, ...>
void print(const T& first, const Rest&... rest)
{
    /*
        typename... Rest        -> declares a type parameter pack
        const Rest&... rest     -> expands the pattern 'const Rest&' for each type
                                   giving: const R1&, const R2&, const R3&, ...
        rest...                 -> expands into: r1, r2, r3, ...
    */
    std::cout << first << " ";
    print(rest...);                      // pack expansion in function call
}

int main()
{
    print_count(1, 3.14, "hello");       // Args = <int, double, const char*>

    std::cout << "TypeList size = "
              << TypeList<int, double, char, bool>::size << '\n';

    print(10, 20.5, "text", 'A');        // T = int, Rest = <double, const char*, char>

    return 0;
}
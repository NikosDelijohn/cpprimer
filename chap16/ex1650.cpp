#include <iostream>

template <typename T> 
void f (T) { std::cout << "(1) f(T)\n";}

template <typename T>
void f(const T*) { std::cout << "(2) f(const T*)\n";}

template <typename T>
void g(T) { std::cout << "(3) g(T)\n";}

template <typename T>
void g(T*) { std::cout << "(4) g(T*)\n";}

int main()
{
    int i = 42, *p = &i;
    const int ci = 0, *p2 = &ci;

    g(42); // (3) Exact match T = int
    f(42); // (1) Exact match T = int

    g(p); // (4) Both valid but 4 is more specialized than 3
    f(p); // (1) T = int* is exact match. 2 requires conversion to const which is worse than exact match

    g(ci); // (3) T = const int. 4 requires ptr
    f(ci); // (1) same as above

    g(p2); // (4) Both valid but 4 is more specialized than 3
    f(p2); // (2) Both valid but 2 is more specialized than 1

    return EXIT_SUCCESS;
}
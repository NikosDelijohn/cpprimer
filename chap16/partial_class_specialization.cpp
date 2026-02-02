#include <iostream>
#include
template<typename T> 
struct remove_reference 
{
    remove_reference() {std::cout << "original\n";}
    using type = T;
};

template<typename T>
struct remove_reference<T&>
{
    remove_reference() { std::cout << "T& partial specialization\n";}
    using type = T;

};

template<typename T>
struct remove_reference<T&&>
{
    remove_reference() { std::cout << "T&& partial specialization\n";}
    using type = T;
};

int main()
{

    int i;

    remove_reference<decltype(42)>::type // -> decltype(42) is int hence its the default template
    remove_reference<decltype((i))>::type; // -> this yields an lvalue ref thus its the T&
    remove_reference<decltype(std::move(i))>::type; // -> move yields an rvalue ref thus its the T&&

    return EXIT_SUCCESS;
}
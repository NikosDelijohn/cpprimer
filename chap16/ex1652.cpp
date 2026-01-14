#include <iostream>
#include <string>

template <typename T, typename... Args>
void foo (const T &t, const Args& ... rest)
{
    std::cout << sizeof...(Args) << " template arguments\n";
    std::cout << sizeof...(rest) << " function arguments\n";
}

int main()
{

    int i = 0;
    double d = 3.14; 
    std::string s {"A STRING"}; 

    foo(i, s, 42, d);
    foo(s, 42, "hi");
    foo(d,s);
    foo("hi");

    return EXIT_SUCCESS;
}
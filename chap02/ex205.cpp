#include <typeinfo>
#include <iostream>

int main()
{   
    std::cout << typeid('a').name() << std::endl; // char
    std::cout << typeid(L'a').name() << std::endl; // wide char
    std::cout << typeid("a").name() << std::endl; // string size 1+1 = 2b
    std::cout << typeid(L"a").name() << std::endl; // wide string 1+1 = 2b

    return 0;
}
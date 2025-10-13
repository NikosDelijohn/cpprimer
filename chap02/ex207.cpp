#include <typeinfo>
#include <iostream>

int main()
{   
    std::cout << typeid("Who goes with F\145rgus?\012").name() << std::endl; // string
    std::cout << typeid(3.14e1L).name() << std::endl; // Long double
    //std::cout << typeid(1024f).name() << std::endl; // invalid. f is for floats and literal is an int
    std::cout << typeid(3.14L).name() << std::endl; // Long double

    return 0;
}
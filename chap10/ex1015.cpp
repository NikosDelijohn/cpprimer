#include <iostream>

int main()
{
    int a = 41;

    auto sum = [a](const  int b) -> int {return a + b;};

    std::cout << sum(1) << std::endl;
}
#include <iostream>

int main()
{
    auto sum = [](const int a, const  int b) -> int {return a + b;};

    std::cout << sum(1,2) << std::endl;
}
#include <iostream>

int main()
{
    int a, b;

    std::cout << "Give me two numbers [a,b] with a being less than b" << std::endl;
    std::cin >> a >> b;


    while (a <= b)
    {
        std::cout << a << std::endl;
        ++a;
    }

    return 0;
}
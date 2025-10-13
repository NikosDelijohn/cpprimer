#include <iostream>

int main()
{
    int a, b, c;

    std::cout << "Give me two numbers: " << std::endl;
    std::cin >> a >> b;
    
    if (b <= a)
    {   
        c = a;
        a = b;
        b = c;
    }

    while (a <= b)
    {
        std::cout << a << std::endl;
        ++a;
    }

    return 0;
}
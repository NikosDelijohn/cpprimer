#include <iostream>

int main()
{
    int num;
    std::cin >> num;

    if (!(num % 2))
    {
        std::cout << "Is even!" << std::endl;
    }
    else
    {
        std::cout << "Is odd!" << std::endl;
    }

    return 0;
}
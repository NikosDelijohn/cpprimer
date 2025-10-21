#include <iostream>

int main()
{
    int val;

    while (std::cin >> val && val != 42)
    {
        std::cout << val << std::endl;
    }

    return 0;
}
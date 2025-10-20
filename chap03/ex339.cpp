#include <iostream>
#include <string>
#include <cstring>

int main()
{
    std::string sa, sb;

    std::cin >> sa >> sb;

    if (sa == sb)
    {
        std::cout << "strings are equal" << std::endl;
    }
    else
    {
        std::cout << "strings are NOT equal" << std::endl;
    }

    const unsigned buffer_size = 256u;
    char csa[buffer_size] = "First String";
    char csb[buffer_size] = "First String";

    if (strcmp(csa, csb) == 0)
    {
        std::cout << "Cstrings are equal!" << std::endl;
    }
    else
    {
        std::cout << "Cstrings are NOT equal!" << std::endl;
    }

    return 0;
}
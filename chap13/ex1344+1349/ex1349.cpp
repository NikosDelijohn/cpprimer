#include "string.hpp"
#include <iostream>

void print_str(const string &str)
{
    for (size_t idx = 0u; idx < str.size(); ++idx)
    {
        std::cout << *(str.begin() + idx) << std::ends;
    }
    std::cout << std::endl;
}

int main()
{

    string tmp("Haha!");
    string B = std::move(tmp); // Move constructor is called

    print_str(B);

    return EXIT_SUCCESS;
}
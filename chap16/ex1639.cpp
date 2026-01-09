#include <iostream>
#include <string>

template <typename T>
bool compare(const T& a, const T& b)
{
    return a < b;
}


int main()
{
    std::cout << compare<std::string>("aaaa","bbbb") << std::endl;
}
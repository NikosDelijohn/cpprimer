#include <iostream>

int main()
{
    int i = 5;
    double d = 6.5;

    i *= static_cast<int>(d); // if not for integral mult the res would be 32,5 truncated to 32

    std::cout << i << std::endl;

    return 0;
}
#include <iostream>

void reset(int &val)
{
    val = 0;
}

int main()
{
    int value = 50;
    reset(value);
    std::cout << value << std::endl;

    return 0;
}
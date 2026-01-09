#include <iostream>

int main()
{

    std::max<int>(5,2.0);    // double is narrowed down to int.
    std::max<float>(2.0, 5); // int is converted to float.
}
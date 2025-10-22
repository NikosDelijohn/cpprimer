#include <iostream>

int main()
{
    constexpr int size = 5;
    
    int ia[size] = {1,2,3,4,5};

    for (int *ptr = ia, ix = 0; ix != size && ptr != ia+size; ++ix, ++ptr)
    {
        std::cout << *ptr << std::endl; // simply traverses the list. conditions have redundant checks to see whether we reached the end of the list 
    }

    return 0;
}
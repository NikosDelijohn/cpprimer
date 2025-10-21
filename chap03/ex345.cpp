#include <iostream>

int main()
{

    int ia[3][4] = 
    {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12}
    };

    for (auto row = 0; row < 3; ++row)
    {
        for (auto col = 0; col < 4; ++col)
        {
            std::cout << ia[row][col] << ' ';
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;

    for (auto p = ia; p < ia + 3; ++p)
    {
        for (auto q = *p; q < *p + 4; ++q)
        {
            std::cout << *q << ' ';
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;

    for (auto &row : ia) // beware & is mandatory for each outter loop. besides the innermost one to avoid array decay to ptrs!
    {
        for (auto col : row)
        {
            std::cout << col << ' ' ;
        }
        std::cout << std::endl;
    }

    return 0;
}
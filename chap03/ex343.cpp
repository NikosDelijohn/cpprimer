#include <iostream>

int main()
{

    int ia[3][4] = 
    {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12}
    };

    for (size_t row = 0; row < 3; ++row)
    {
        for (size_t col = 0; col < 4; ++col)
        {
            std::cout << ia[row][col] << ' ';
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;

    for (int (*p)[4] = ia; p < ia + 3; ++p)
    {
        for (int *q = *p; q < *p + 4; ++q)
        {
            std::cout << *q << ' ';
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;

    for (auto &row : ia)
    {
        for (auto col : row)
        {
            std::cout << col << ' ' ;
        }
        std::cout << std::endl;
    }

    return 0;
}
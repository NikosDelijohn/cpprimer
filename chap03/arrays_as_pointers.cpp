#include <iostream>
#include "../help.hpp"

int main()
{
    int ia[] = {0,1,2,3,4,5};
    auto ia2 = ia;
    auto ia3(ia); // dont forget direct init
    
    std::cout << type_name(ia2) << std::endl; // its int* !

    decltype(ia) ia4;
    std::cout << type_name(ia4) << std::endl; // its int [6] !!

    int *p = &ia[2]; // pointer to the second element of ia -or- equivalently
    // int *p = ia+2
    int j = p[1]; // this is *(p + 1) == *(ia + 2 + 1)
    int k = p[-2]; // this is *(p - 2) == *(ia + 2 - 2)

    // We cannot use negative subscripts in std library types (vectors, strings)!

    return 0;
}
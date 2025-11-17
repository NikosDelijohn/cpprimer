#include <iostream>
#include <vector>

int main()
{
    std::vector<int> ivec = {1,2,3,4,5,6,8,9,10};

    for (std::vector<int>::const_reverse_iterator rit = ivec.crbegin(); rit != ivec.crend(); ++rit)
        std::cout << *rit << " " << std::ends;
    std::cout << std::endl;

    return EXIT_SUCCESS;
    
}
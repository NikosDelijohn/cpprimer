#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

int main()
{
    std::vector<int> ivec = {0,1,2,3,4,5,6,7,8,9,10};

    std::list<int> ilist(ivec.crbegin()+3, ivec.crend()-3);

    for (auto &elem: ilist)
        std::cout << elem << " " << std::ends;
    std::cout << std::endl;

    return EXIT_SUCCESS;
    
}
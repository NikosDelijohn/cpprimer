#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> ivec = {1,2,0,4,0,6,8,0,10};

    auto find_iter = std::find(ivec.crbegin(), ivec.crend(), 0);

    std::cout << *find_iter << " at index " << find_iter.base() - ivec.begin() - 1  <<std::endl; // -1 because base points to one past the current element

    return EXIT_SUCCESS;
    
}
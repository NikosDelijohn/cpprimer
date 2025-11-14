#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

int main()
{
    std::vector<int> source = {1,1,1,2,4,4,5,6,7,8,8,8,8,9,10,11};
    std::list<int> dest;

    std::unique_copy(source.begin(), source.end(), std::back_inserter(dest));

    for (auto &elem: dest) std::cout << elem << " " << std::ends;

    std::cout << std::endl;

    return EXIT_SUCCESS;
}
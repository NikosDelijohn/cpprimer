#include <iostream>
#include <vector>
#include <numeric>

int main()
{
    std::vector<int> vec = {1,2,3,4,5,6,7,8,9,10};

    std::cout << "Sum: " << std::accumulate(vec.begin(), vec.end(), 0u) << std::endl;

    return EXIT_SUCCESS;
}
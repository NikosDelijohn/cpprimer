#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

int main()
{
    std::vector<int> vec;
    auto it = std::back_inserter(vec);

    std::fill_n(it, 10, 0);

    return EXIT_SUCCESS;
}
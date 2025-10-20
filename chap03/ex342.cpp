#include <iostream>
#include <vector>

int main()
{
    std::vector<int> vec{1,2,3,4,5};
    int arr[5] = {};

    std::vector<int>::size_type idx;
    ptrdiff_t arrsize = std::end(arr) - std::begin(arr);

    for (idx = 0u; idx < vec.size() && idx < arrsize; ++idx)
    {
        arr[idx] = vec[idx];
    }

    for (auto elem: arr)
    {
        std::cout << elem << std::endl;
    }

    return 0;
}
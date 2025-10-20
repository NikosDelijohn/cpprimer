#include <iostream>
#include <vector>

int main()
{

    int arr[4] = {1,2,3,4};
    std::vector<int> vec(std::begin(arr), std::end(arr));

    for (auto val: vec)
        std::cout << val << std::endl;

    return 0;
}
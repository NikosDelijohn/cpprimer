#include <iostream>

int main()
{

    int arr[20];

    auto *start = std::begin(arr);
    auto *end = std::end(arr);

    while(start != end)
    {
        *start = 0;
        ++start;
    }

    for (auto elem : arr)
        std::cout << elem << std::endl;
}
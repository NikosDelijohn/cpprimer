#include <iostream>

int main()
{
    const size_t size = 10;
    int arr[size] = {};

    for (size_t i = 0; i < size; ++i)
        arr[i] = i;
    
    for (auto elem : arr)
        std::cout << elem << std::endl;

    return 0;
}
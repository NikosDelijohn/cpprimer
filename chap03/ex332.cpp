#include <iostream>
#include <vector>

int main()
{
    const size_t size = 10;
    int arr[size] = {};
    int arr2[size] = {};

    for (size_t i = 0; i < size; ++i)
    {
        arr[i] = i;
        arr2[i] = arr[i]; // copy of arr
    }

    std::vector<int> vec;
    for (size_t i = 0; i < size; ++i)
    {
        vec.push_back(i);
    }
    //copy in vector
    std::vector<int> vec2 = vec;


    return 0;
}
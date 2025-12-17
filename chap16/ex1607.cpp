#include <iostream>

template <typename T, unsigned N>
constexpr 
unsigned size_of_arr(const T (&arr)[N])
{
    return N;
}

int main()
{
    int arr[5] = {0};

    std::cout << size_of_arr(arr) << std::endl;
}
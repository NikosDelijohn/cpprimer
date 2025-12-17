#include <iostream>

template <typename T, unsigned N>
T* begin(T (&arr)[N])
{
    return &arr[0]; // or return arr -> array to pointer decay ;)
}

template <typename T, unsigned N>
const T* begin(const T (&arr)[N])
{
    return &arr[0];
}


template <typename T, unsigned N>
T* end(T (&arr)[N])
{
    return &arr[N]; // or return arr + N -> array to pointer decay again.
}

template <typename T, unsigned N>
const T* end(const T (&arr)[N])
{
    return &arr[N]; // or return arr + N -> array to pointer decay again.
}

template<typename T, unsigned N>
void print(T (&arr)[N])
{
    T* it = begin(arr);
    while (it != end(arr))
        std::cout << *it++ << std::endl;
}


int main()
{

    int arr[] = {1,2,3,4};
    print(arr);

    return EXIT_SUCCESS;
}
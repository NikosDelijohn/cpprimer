#include <cassert>
#include <iostream>

void print(const int ia[], size_t size)
{
#ifndef NDEBUG
    std::cout << __FILE__ << " " << __LINE__ << " " << __TIME__ " " << __func__ << std::endl;

#endif
    std::cout << "array has size " << size << std::endl;
}

int main()
{
    int arr [10];
    print(arr, 10);

    // if compiled with -D NDEBUG then the first print will be omitted!
}
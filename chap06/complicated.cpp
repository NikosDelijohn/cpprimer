#include <iostream>

typedef int arr_int[10];
// -or- equivalently
using arr_int_2 = int[10];

// Returns a pointer to an array of ten integers
arr_int* func(arr_int &arr)
{
    for (auto &elem: arr)
        elem+=1;

    return &arr;
}

// Now, without typedef/using
int (*equiv_func(int (&arr)[10]))[10]
{
    for (auto &elem: arr)
        elem+=1;

    return &arr;
}
// step by step
// 1. equiv_func(int (&arr)[10])
//      takes as input a ref to an array of 10 ints
// 2. (*equiv_func(int (&arr)[10])
//      the result of the func can be dereferenced
// 3. (*equiv_func(int (&arr)[10])
//      dereferecing the result of the function yields an array of 10 elements
// 4. int (*equiv_func(int (&arr)[10])
//      dereferecing the result of the function yields an array of 10 integer elements
// YIKES...

// But, trailing return type helps more:

// auto                                 -> return types
auto another_equiv_func(int (&arr)[10]) -> int(*)[10] // note the () around * to indicate a pointer to array and not array of pointers.
{
    for (auto &elem: arr)
        elem+=1;

    return &arr;
}

int main()
{
    arr_int arr = {1,2,3,4,5,6,7,8,9,10};

    for (auto &elem: arr)
        std::cout << elem << " ";
    std::cout << std::endl;

    func(arr);

    for (auto &elem: arr)
        std::cout << elem << " ";
    std::cout << std::endl;

    // --------------------------

    arr_int_2 arr2 = {1,2,3,4,5,6,7,8,9,10};
   
    for (auto &elem: arr2)
        std::cout << elem << " ";
    std::cout << std::endl;

    equiv_func(arr2);

    for (auto &elem: arr2)
        std::cout << elem << " ";
    std::cout << std::endl;

    // --------------------------

    arr_int arr3 = {1,2,3,4,5,6,7,8,9,10};

    for (auto &elem: arr3)
        std::cout << elem << " ";
    std::cout << std::endl;

    another_equiv_func(arr3);

    for (auto &elem: arr3)
        std::cout << elem << " ";
    std::cout << std::endl;

    return 0;
}
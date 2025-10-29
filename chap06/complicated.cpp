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

/*
  _____      _                         _    ______                
 |  __ \    | |                     /\| |/\|  ____|               
 | |__) |___| |_ _   _ _ __ _ __    \ ` ' /| |__ _   _ _ __   ___ 
 |  _  // _ \ __| | | | '__| '_ \  |_     _|  __| | | | '_ \ / __|
 | | \ \  __/ |_| |_| | |  | | | |  / , . \| |  | |_| | | | | (__ 
 |_|  \_\___|\__|\__,_|_|  |_| |_|  \/|_|\/|_|   \__,_|_| |_|\___|
                                                                  
                                                                  
*/

// Functions that return pointers to functions . . .
// Assume the pointee function that computes the sum of an int array elements
int sum(int* arr, int size)
{
    int s = 0;
    for (int i = 0; i < size; ++i)
        s+=arr[i];
    return s;
}

using F = int(int*, int); // function
using PF = int(*)(int*,int); // pointer to function

PF f1(int); // f1 returns a pointer to a function 
F *f2(int); // f1 returns a pointer to a function (equivalent)

// BUT...without type aliasing...

int (*f3(int))(int*, int);
// step by step 
// 1. f3 has a paremeter list, so its a function
// 2. f3 is preceeded by the dereference operator and its enclosed to parens so it returns a pointer
// 3. The pointer itself has its own parameter list (int*, int) so it returns a pointer to a function
// 4. The pointee function returns an int (leftmost int)
// BIG BIG YIKES...

// But once gain, trailing return helps more:
auto f4(int) -> int (*)(int*, int); // more human readable.

// A working example, factory pattern 
// factory returns for key 1 min, for key 2 max

int min(int * arr, size_t elements)
{
#ifndef NDEBUG
    std::cout << __func__ << " is invoked!" << std::endl;
#endif 
    if (elements < 1)
        return arr[0];
    
    int minval = arr[0];
    for (size_t idx = 1u; idx < elements; ++idx)
    {
        if (minval > arr[idx])
        {
            minval = arr[idx];
        }

    }
    return minval;
}

int max(int * arr, size_t elements)
{
#ifndef NDEBUG
    std::cout << __func__ << " is invoked!" << std::endl;
#endif 
    if (elements < 1)
        return arr[0];
    
    int maxval = arr[0];
    for (size_t idx = 1u; idx < elements; ++idx)
    {
        if (maxval < arr[idx])
        {
            maxval = arr[idx];
        }

    }
    return maxval;    
}

// without type aliasing
int (*factory(size_t key))(int *, size_t)
{
    return (key == 1)? min : (key == 2) ? max : nullptr;
}

// with type aliasing
using FF = int (int*, size_t);
FF *equivalent_factory(size_t key)
{                   // & is equivalent here& with previous and next functions' statements
    return (key == 1)? &min : (key == 2) ? &max : nullptr;
}

// with trailing return type
auto another_equiv_factory(size_t key) -> int (*)(int*, size_t)
{
    return (key == 1)? min : (key == 2) ? max : nullptr;
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

    // --------[RET FUNC *]--------------

    int arr4[5] = {1,2,3,4,5};

    decltype(max) *factory_func = factory(1u);
    std::cout << factory_func(arr4, 5u) << std::endl;   // expect 1

    factory_func = factory(2u);
    std::cout << factory_func(arr4, 5u) << std::endl;   // expect 5

    // --------------------------
    factory_func = equivalent_factory(1u);
    std::cout << factory_func(arr4, 5u) << std::endl;   // expect 1

    factory_func = equivalent_factory(2u);
    std::cout << factory_func(arr4, 5u) << std::endl;   // expect 5

    // --------------------------
    factory_func = another_equiv_factory(1u);
    std::cout << factory_func(arr4, 5u) << std::endl;   // expect 1

    factory_func = another_equiv_factory(2u);
    std::cout << factory_func(arr4, 5u) << std::endl;   // expect 5

    return 0;
}
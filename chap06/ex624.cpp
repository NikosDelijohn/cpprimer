#include <iostream>

// pointer decay occurs. 
// this is equivalent to const int* 
// the size is not kept and is not part of type!
// the parameter is not an const int[10] but a const int* !!!! 
void print(const int ia[10])
{   
    // NO SIZE CHECK HERE!
    for (size_t i = 0; i != 10; ++i)
        std::cout << ia[i] << "  ";
    std::cout << std::endl;
}

int main()
{
    int arr[]{1,2,3,4};
    int arr2[15]{0};
    print(arr); // no size check in function print. will violate array bounds! -> UNDEFINED BEHAVIOR

    print(arr2); // this will also work, but only the first 10 zeroes will be printed out!!

}
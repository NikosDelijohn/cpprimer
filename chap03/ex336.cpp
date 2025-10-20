#include <iostream>
#include <vector>

int main()
{   
    //int arr1eq[]= {1,2,3,4,5}; // size differs
    int arr1eq[] = {1,3,2,4,5,6}; // differing element
    //int arr1eq [] = {1,2,3,4,5,6}; // equal

    int arr2eq [] = {1,2,3,4,5,6};
    bool equal = true;

    ptrdiff_t arr1size = std::end(arr1eq) - std::begin(arr1eq);
    ptrdiff_t arr2size = std::end(arr2eq) - std::begin(arr2eq); 

    if (arr1size != arr2size)
    {
        std::cout << "Arrays have differing lengths! Not equal!" << std::endl;
        equal = false;
        return 0;
    }
    
    for (size_t idx = 0u; idx < arr1size /* or arr2size */; idx++)
    {
        if (arr1eq[idx] != arr2eq[idx])
        {
            equal = false;
        }
    }

    if (!equal)
    {
        std::cout << "Arrays are not equal!!" << std::endl;
    }
    else
    {
        std::cout << "Arrays are equal!!" << std::endl;
    }

    std::vector<int> vec1{1,2,3,4,5};
    std::vector<int> vec2{1,2,3,4,5};

    if (vec1 == vec2)
    {
        std::cout << "Vectors are equal!" << std::endl;
    }
    else
    {
        std::cout << "Vectors are unequal" << std::endl;
    }
    
    return 0;
}
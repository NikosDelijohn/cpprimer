#include <iostream>

// --------------------------------------------
// Function takes a pointer to an array of 10 ints: int (*)[10]
// So 'matrix' points to an entire array of 10 integers.
// --------------------------------------------
void func(int (*matrix)[10])
{
    // Dereferencing 'matrix' gives that actual array (type: int[10])
    // so std::begin(*matrix) gives pointer to its first int
    auto beg = std::begin(*matrix);
    auto end = std::end(*matrix);

    while(beg != end)
    {
        std::cout << *beg++ << " ";  // print each integer in the array
    }
    std::cout << std::endl;
}

// --------------------------------------------
// Equivalent form using array syntax.
// In a parameter list, "int matrix[][10]" is rewritten by the compiler
// as "int (*matrix)[10]".
// The first dimension is ignored (decays to pointer).
// --------------------------------------------
void equivalent_func(int matrix[][10])
{
    auto beg = std::begin(*matrix);
    auto end = std::end(*matrix);

    while(beg != end)
    {
        std::cout << *beg++ << " ";
    }
    std::cout << std::endl;   
}

// SAFE.
// The parameter is a reference not a ptr.
// Hence, the parameter is 'reference to an array of 10 integers
// So the body of the func is safe. Exactly 10 elements exist!
void size_is_part_of_type(int (&arr)[10])
{
    for (size_t i = 0u; i != 10; ++i)
        std::cout << i << std::endl;
}

// UNSAFE.
// The parameter is NOT an array.
// Pointer decay happens here and the size is actually
// const int *. The dimension is not kept and this is 
// misleading. No guarantees occur to limit the number 
// of elements to 10! In fact there is no guarantee 
// that the array will have less or greater than 10 elements
void size_is_NOT_part_of_type(const int ia[10])
{   
    // NO SIZE CHECK HERE!
    for (size_t i = 0; i != 10; ++i)
        std::cout << ia[i] << std::endl;
}

int main()
{
    // A simple 1D array of 10 ints.
    int matrix[10] = {1,2,3,4,5,6,7,8,9,10};

    // &matrix has type "int (*)[10]" (pointer to an array of 10 ints)
    // So it matches the parameter type perfectly.
    func(&matrix);
    equivalent_func(&matrix);

    int two_d_matrix[2][10] = 
    {
        {-1,-2,-3,-4,-5,-6,-7,-8,-9,-10},
        {11,12} // the rest are zero-initialized
    };

    // --------------------------------------------
    // Passing a 2D array is also valid.
    // 'two_d_matrix' decays to a pointer to its first row,
    // i.e. type "int (*)[10]".
    // So both calls below are legal.
    // --------------------------------------------

    func(two_d_matrix);
    equivalent_func(two_d_matrix);

    // However, note: inside func() we print only *matrix,
    // i.e. the first array of 10 ints (the first row).
    // The second row is never accessed or printed.
    // To print the whole 2D array, you'd need to loop over the rows
    // as well.

}

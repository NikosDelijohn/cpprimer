#include <iostream>

int main()
{
    // alias declaration (>= std++11)
    using d = double;
    using dd = d *; // double *
    using ddd = dd *; // double **

    d pi = 3.14;
    dd ptr_to_pi = &pi;
    ddd ptr_to_ptr = &ptr_to_pi;
    std::cout << ((*ptr_to_pi == pi) && (**ptr_to_ptr == *ptr_to_pi)) << std::endl; // expecting 1
    
    // old school
    typedef int *i; // int *
    typedef i *ii; // int **

    int value = 10;
    int *ptr = &value;
    i tptr = ptr;
    ii tptr_to_tptr = &tptr;

    std::cout << ((ptr == tptr) && (*ptr == *tptr)) << std::endl; // expecting 1
    std::cout << ((**tptr_to_tptr == *tptr)) << std::endl; // expecting 1

    // constants however...

    const int *ptr_to_const = &value; // low-level const pointing to non-const -> okay!
    // BUT:
    // const i const_ptr; // wrong, ITS A high-level const => int *const i so must be initialized ! Hence =
    const i const_ptr = &value;
    /*
    so it is not correct to think of it as a substitution to 
    const int * const_ptr which in turn is a low-level const (pointer to const int)

    and thus, being a high-level const it cannot be re-assigned
    */
    int another_val = 100;
    //const_ptr = &another_val; // wrong, assignment of read-only variable!!

    const i *const_ptr_to_ptr; // but this is valid. Its a pointer to a constant pointer to int (low-level const)
    const i &ref = const_ptr; // ok, reference to const integer pointer
    const_ptr_to_ptr = &const_ptr; // fine. its low-level const so it can be re-assigned.

    // arrays 
    using int_array = int[4];
    int_array arr = {1,2,3,4};

    // equivalent to 
    typedef int int_array2[4];
    int_array2 arr2 = {1,2,3,4}; 

    return 0;
}
#include <iostream>
#include <string>

using std::string;

int foo() { return 1337; }

// Compile with -pedantic-errors ! //

int main()
{
    // Here, we also have a DEFAULT initialization of the containers' elements
    int arr[5]; // ok, array of 5 integers.
    int arr2[5u]; // ok, array of 5 integers.
    //int arr3[-1]; // wrong, array of -1 integers. pointless.
    //int arr_copy[5] = arr; // wrong, copy is NOT allowed

    /*
    The following definitions are WRONG according to the C++ ISO. 
    However, the compiler may allow for the following statements 
    unless the '-pedantic-errors' flag is selected during compilation.

    The statements are invalid because the C++ ISO does not allow
    for variable-length array. They are being initialized with 
    a non-const variable. Meaning, that this number may be modified
    at run-time. 
    */

    // unsigned a_normal_var = 42;
    // int arr4[a_normal_var];  
    // int arr5[foo()];
   
    /* The following (arr6) is wrong for the reason explained at chap02/constexpr.cpp:
    
    Albeit ptr is a high and low level const, meaning that it cannot change after
    initialization, it is allowed to be initialized at RUNTIME. Which makes it 
    illegal. To do that, we need constexpr instead.
    */
    
    // const int num = 4;
    // const int *const ptr = &num;
    // int arr6[*ptr];

    // Allowed statements with const size variables. 
    constexpr unsigned b_constexpr_var = 42;
    int arr7[b_constexpr_var]; 
    // Or even just with const as long as it a basic type like e.g
    const unsigned c_const_var = 24;
    int arr8[c_const_var];

    int *iptrs[c_const_var]; // Array of 24 pointers to int!

    /* 
    This is also not valid. 

    int a = 1, b = 2, c = 3, &ra = a, &rb = b, &rc = c; //ok
    int &refArrs[] = {a, b, c};

    Because arrays must contain elements that are objects. References are NOT objects.
   */

    // 
    
    /*
    INITIALIZATION
    */

    const unsigned sz = 3;

    int iarr0[sz] = {}; // value initialization to 0
    int iarr1[sz] = {1,2,3};
    int iarr2[] = {1,2,3}; // ok, size is inferred by number of initializers.
    int iarr3[5] = {0,1,2}; // ok, array is [0, 1, 2, 0 0] non initializer-mapped values are VALUE initialized and not DEFAULT initialized
    string sarr1[3] = {"Hello", "Mate"}; // ok array is ["Hello", "Mate", ""]
    //int err1[2] = {0, 1, 2}; // wrong, too many initializers!

    // CHARACTER ARRAYS

    // 1st init way:
    char carr1[] = {'C','+','+'}; // No null terminator!
    std::cout << (carr1[3] == '\0') << std::endl; // expect 0. Actually, accessing [4] is undefined! carr1 is size 3 not 4! Null  doesnt exist
    
    char carr2[] = {'C','+','+','\0'}; // Explicit null 
    
    // 2nd init way:
    char carr3[] = "C++"; // CONTAINS NULL terminator automatically
    //char carr4[5] = "Nikos"; //Error! Not enough space for null!
    char carr5[6] = "Nikos"; //Ok, exactly 6 characters (including NULL)


    // Complicated Array Declarations
    int narr[10]= {0,1,2,3,4};
    int (* Parray) [10]; // Pointer to an array of 10 ints! TO THE WHOLE ARRAY not the first element
    Parray = &narr; 
    int (& refArray) [10] = narr; // Reference to an array of 10 ints.

    std::cout << (*Parray[0] == narr[0] && *Parray[0] == *narr) << std::endl; // expect 1
    
    int *ptrArray[10];
    int *(& refArray2) [10] = ptrArray;
    int *(* ptrArray2) [10] = &ptrArray;

    int (**ptrPtrArray) [10] = &Parray; // Pointer to Pointer to an array of 10 ints! 
    
    std::cout << (*ptrPtrArray == Parray) << (**ptrPtrArray[0] == *Parray[0]) << (**ptrPtrArray[0] == narr[0]) << std::endl; // Expect 111


    // range for 

    for (auto elem: iarr1)
    {
        std::cout << elem << std::endl;
    }
    return 0;
}
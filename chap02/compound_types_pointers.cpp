#include <iostream>
#include <string>
using std::string;

bool lengthCompare(const string&, const string &);
bool wrapper(const string& s1, const string& s2,
             bool (const string&, const string&));
// or equivalently (since functions decay to ptrs to functions)
bool wrapper(const string& s1, const string& s2, 
             bool (*)(const string&, const string&));

int main()
{
    int value = 10, &ref_value = value;
    int *ptr_value = &ref_value;
    int *another_ptr = &value;

    std::cout << (ptr_value == another_ptr) << std::endl; // expect 1 (true)
    std::cout << ptr_value << " = " << *ptr_value << std::endl; // expect 0xADDRESS = 10

    int value_b = 20; 
    another_ptr = &value_b;

    int &another_ref = *another_ptr;

    std::cout << another_ref << std::endl;
    another_ref = 100;
    std::cout << value_b << " == " << another_ref << " == " << *another_ptr << std::endl; // expect 100 == 100 == 100
 
    int **ptr_to_ptr = &another_ptr;

    std::cout << another_ptr << "->" << *another_ptr << std::endl 
              << ptr_to_ptr << "->" << *ptr_to_ptr << "->" << **ptr_to_ptr << std::endl;

    int *ptr_to_zero = nullptr;
    int *ptr_to_val = &value;
    int *uninit_ptr;

    if (ptr_to_zero)
    {
        std::cout << "You shall never reach this point!" << std::endl;
    }

    if (ptr_to_val)
    {
        std:: cout << "Valid pointer. Hence, Hi!" << std::endl;
    }

    if (uninit_ptr)
    {   
        std::cout << "Uninitialized pointer has non-null value. Dangerous! (" << uninit_ptr << ")" << std::endl;
    }
    
    int arr[3] = {1,2,3};
    int *p_to_arr = arr;
    int *another_p_to_arr = arr;

    // more than one past the end (pg. 56 text)
    p_to_arr += 5;
    another_p_to_arr += 5;
    // This is undefined. We are way beyond the boundaries of our array.
    // Potentially will be equal, but thats undefined behavior.
    std::cout << (p_to_arr == another_p_to_arr) << std::endl;

    // @@@@@@@@@@@@@@@@@@@@@ VOID POINTERS @@@@@@@@@@@@@@@@@@@@@

    void *boo = nullptr; // valid. void ptrs can point to anything
    
    double pi = 3.14;
    double *ptr_to_pi = &pi; 

    boo = ptr_to_pi;
    if (boo == ptr_to_pi)
    {
        std::cout << "Valid! They are equal" << std::endl;
    }

    // std::cout << "Trying to de-reference it now: " << *boo << std::endl;
    // erroneous. Trying to dereference a void pointer
    /*
compound_types_pointers.cpp:69:55: error: ‘void*’ is not a pointer-to-object type
   69 |     std::cout << "Trying to de-reference it now: " << *boo << std::endl;
      |                                                       ^~~~
    */

    // If you know the type of the value the void pointer points to
    // you can cast it to another pointer of the same type.
    double *yet_another_ptr = (double*) boo; 
    std::cout << "Try now: " << *yet_another_ptr << std::endl;
    std::cout << "Or directly as: " << *((double *) boo) << std::endl;

    // @@@@@@@@@@@@@@@@@@@@@ POINTERS TO CONST @@@@@@@@@@@@@@@@@@@@@
    // Similar to references. They think they point to a const object!

    const int val = 3;
    //int* ptr = &val; // Wrong, cannot convert const int* to int* 
    const int *ptr2c = &val; // ok
    //*ptr = 4; // wrong, cannot change readonly object!
    
    const int *ptr2c_uninitialized; // fine pointer to const int uninitialized!

    const int val2 = 4;
    int val3= 5;
    ptr2c = &val2; // ok! you can change to where the pointer to const points.
    ptr2c = &val3; // ok! you can change to where the pointer to const points even if its a NON-CONST object!
    //*ptr2c = 12; //wrong, still cannot change the object! 
    
    // @@@@@@@@@@@@@@@@@@@@@ CONST POINTERS @@@@@@@@@@@@@@@@@@@@@

    int errorno = 0;
    //int *const cptr; // wrong, a constant pointer MUST be initialized!
    int *const cptr = &errorno;
    //cptr = &value; // wrong, a constant pointer can't be re-assigned.
    *cptr = 10; //ok , the pointer points to an int type

    const int errorno2 = -1;
    const int *const cptr2 = &errorno2;

    //cptr2 = &val2; // wrong, a constant pointer can't be re-assigned.
    //*cptr2 = -10; // wrong, the object the pointer points to is const and can't be re-assigned.


    // @@@@@@@@@@@@@@@@@@@@@ POINTERS TO FUNCTIONS @@@@@@@@@@@@@@@@@@@@@@

    // A function has a type. The function's type is determined by its return type
    // and the types of its parameters. The function name is not part of its type.

    // Hence to declare a pointer to our lengthCompare func we do:
    bool (*pf) (const string&, const string&); // pointer is uninitialized.
    // if we ommit the () around *pf then we just declare a function that returns a ptr to bool!
    
    pf = lengthCompare; // for functions we can ommit the address-of & operator
    pf = &lengthCompare; // equivalent to above

    bool res_a = pf("Hi", "Mark!"); // similarly, we can ommit the dereference * operator
    bool res_b = (*pf)("Hi", "Mark!"); // equivalent to above

    std::cout << (res_a == res_b) << std::endl; // expect 1

    // NO CONVERSION BETWEEN POINTERS TO ONE FUNCTION TYPE AND POINTERS TO ANOTHER FUNCTION TYPE
    // We can assign however nullptr or 0;

    pf = 0; /* or */ pf = nullptr;

    bool res_c = wrapper("Hi","i", &lengthCompare); 
    bool res_d = wrapper("Hi", "b", lengthCompare); // equivalent to above

    std::cout << (res_c == res_d) << std::endl; // expect 1

    // More conveniently, using type aliases and decltype

    // Func and Func2 are function types
    typedef bool Func(const string&, const string&);
    typedef decltype(lengthCompare) Func2; // equivalent to above

    // FuncP and FuncP2 are pointer to function types
    typedef bool (*FuncP)(const string&, const string&);
    typedef decltype(lengthCompare) *FuncP2; // equivalent to above

    // More at chap06/complicated.cpp

    return 0;
}

// function type is: bool(const string&, const string&)
bool lengthCompare(const string& s1, const string &s2)
{
    return s1.size() < s2.size();
}

// 3rd argument is a function here! However functions cannot be copied similar to arrays. they decay to pointers to functions like arrays decay as ptrs to arrays
// automatically here, evaluator is treated as a pointer to a function!!!!!!!!!
bool wrapper(const string& s1, const string& s2,
             bool evaluator(const string&, const string&))
{
    return evaluator(s1, s2);
}
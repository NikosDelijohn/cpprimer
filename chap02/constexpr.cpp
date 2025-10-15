#include <iostream>

int global_value = 10;

int foo () { return 123; }

int main()
{

    // constexpr imposes a top - level const to the type it is applied.

    int value = 10;

    // constexpr int *ptr = &value; // fails because value's address wont be preserved when its inside a function (although its main, same rules apply)
    constexpr int *ptr = &global_value; // ok. (imposes a top-level const) - its value can't change, the pointed to value can change
    *ptr = 55;
    
    constexpr const int *ptr2 = &global_value; // also ok. it imposes now a second const-int low level const. - its value can't change, the pointed to value can't change! 

    constexpr const int *ptr3 = &global_value; // A.
    const int *const ptr4 = &global_value; // B.

    /*
    A and B are semantically equivalent!
        They both impose a high-level const (pointer cannot change) and a low-level const (pointee cannot change)

    HOWEVER, 
        B. allows for ptr4 to be initialized at runtime. So things like:
    */
    int run_time_var = foo();
    const int *const ptr5 = &run_time_var;
    /*
    are valid but 
        A. mandates that all values must be known at compile time and thus you cannot do:
    */
    //constexpr const int *ptr6 = &run_time_var;

    return 0;
}
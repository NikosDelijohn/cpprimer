#include <iostream>

int global_value = 10;


// constexpr imposes a top - level const to the type it is applied.

int main()
{
    int value = 10;

    // constexpr int *ptr = &value; // fails because value's address wont be preserved when its inside a function (although its main, same rules apply)
    constexpr int *ptr = &global_value; // ok. (imposes a top-level const) - its value can't change, the pointed to value can change
    constexpr const int *ptr2 = &global_value; // also ok. it imposes now a second const-int low level const. - its value can't change, the pointed to value can't change! 

    return 0;
}
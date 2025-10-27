#include <iostream>

void pass_by_val(int val)
{
    val = 50;
}

void pass_by_ref(int &val)
{
    val = 123;
}

void pass_by_ref2(int *ptr)
{   
    // The parameter itself (pointer) is a distinct copy of the
    // argument &my_value. However, the pointee is the same! 
    *ptr = 321;
}


int main()
{

    int my_value = 1;
    
    std::cout << "Variable my_value is " << my_value << " and after the pass_by_val(my_value) call is ";
    pass_by_val(my_value);
    std::cout << my_value << std::endl;

    // however if we pass by ref

    std::cout << "Variable my_value is " << my_value << " and after the pass_by_ref(my_value) call is ";
    pass_by_ref(my_value);
    std::cout << my_value << std::endl;

    // also
    std::cout << "Variable my_value is " << my_value << " and after the pass_by_ref2(&my_value) call is ";
    pass_by_ref2(&my_value);
    std::cout << my_value << std::endl;

    // const rules still apply. we cannot pass a low-level const
    const int c_value = 42;
    //pass_by_ref(c_value); // wrong, the parameter is int &! Discards const qualifier! but
    pass_by_val(c_value); // its ok. The function parameter is an entirely new variable
    //pass_by_ref2(&c_value); // also not ok! const int* to int* is an invalid conversion because once again it discards const qualifier!

    return 0;
}

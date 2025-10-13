#include <iostream>

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
    
    return 0;
}
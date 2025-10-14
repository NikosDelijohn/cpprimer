#include <iostream>

int main()
{
    int number = 10;
    int another_number = 20;

    int &another_ref = another_number;

    int *p_to_number = &number;

    // change the value of the pointer 
    std::cout << "Ptr was: " << p_to_number << std::endl;
    p_to_number = &another_ref; 
    std::cout << "Ptr  is: " << p_to_number << std::endl;

    // change the value to wich the pointer points
    std::cout << "Ptr address had the value: " << *p_to_number << std::endl;
    *p_to_number = -20;
    std::cout << "Ptr address has the value: " << *p_to_number << ", " << another_ref << std::endl;
    
    return 0;
}
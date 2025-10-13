#include <iostream>
/*
Debug the faulty std::cout (commented out) statement
*/
int main()
{
    int v1 = 5;
    int v2 = 5;

    /*
    std::cout << "The sum of " << v1;
              << "and " << v2;
              << " is " << v1 + v2 << std::endl;
    */

    std::cout << "The sum of " << v1;
    std::cout << " and " << v2;
    std::cout << " is " << v1 + v2 << std::endl;
    return 0;

    // No lhs of operator (stream) for operator << since 1st line was terminated (;)
    // so we change it by adding std::cout 
}
#include <iostream>

int main()
{
    const int intvar = 42;

    //diferences
    auto a_var = intvar; // this is an int 
    a_var = 46; // fine!
    decltype (intvar) d_var = intvar; // this is a const int 
    //d_var = 46; // not fine! this is a const !

    return 0;
}
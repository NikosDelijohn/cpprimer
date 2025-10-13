#include <iostream>

int main()
{
    long double d = 3.1415925367;
    std::cout << d << std::endl;

    /*
list_init_builtin.cpp:8:16: warning: narrowing conversion of ‘d’ from ‘long double’ to ‘int’ [-Wnarrowing]
    8 |     int err = {d}; // warn
      |                ^
list_init_builtin.cpp:9:14: warning: narrowing conversion of ‘d’ from ‘long double’ to ‘int’ [-Wnarrowing]
    9 |     int err2{d}; // warn
      |              ^    
    */
   
    int err = {d}; // warn 
    int err2{d};   // warn  
    int err3 = d;  // ok
    int err4(d);   // ok 

    std::cout << err << " " << err2 << " " 
              << err3 << " " << err4 << std::endl;


    return 0;
}
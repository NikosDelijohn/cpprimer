#include <iostream>
/*
Attempt the compilation of a program which has incorrect nested comments.
*/

int main()
{
    /* this is the first line 
    and now another one which terminates here /* nested comment */ whoopsie!*/
    return 0;
}


//Compilation error: 
//
//ex1.7.cpp: In function ‘int main()’:
//ex1.7.cpp:9:68: error: ‘whoopsie’ was not declared in this scope
//    9 |  now another one which terminates here /* nested comment */ whoopsie!*/
//    |                                                             ^~~~~~~~
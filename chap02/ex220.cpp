#include <iostream>

int main()
{
    int i = 0;
    //double* pd = &i; // wrong 
    //int* pi = i; // wrong 
 
    int* p = &i; // ok

    //long *lp = &i; // wrong

    return 0;
}
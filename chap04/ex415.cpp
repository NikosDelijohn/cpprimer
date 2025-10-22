#include <iostream>

int main()
{

    double dval; int ival; int *pi = &ival;

    //dval = ival = pi = 0; // error trying to convert int* to int
    dval = ival = *pi = 0; // this will do the trick  (pi must be also initialized or point to something valid. Else undefined behavior!!)

    return 0;
}
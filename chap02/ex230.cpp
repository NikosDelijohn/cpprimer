#include <iostream>

int main()
{
    int i = 10;
    const int v2 = 0; // low-level const
    int v1 = v2; // no const 
    int *p1 = &v1, &r1 = v1; // no const 
    const int *p2 = &v2, *const p3 = &i, &r2=v2; // low level for p2, high and low level for p3, low level for r2
    
    r1 = v2; // ok! r1 is simply bound to v1. the value of v1 will change

    //p1 = p2; // wrong, p1 is not a pointer-to-const and p2 is a low-level const pointer 
    
    p2 = p1; // ok! no problem for a pointer-to-const to point to a non-const obj

    //p1 = p3 // wrong, p1 is not a pointer-to-const but p3 is a pointer-to-const (low-level)

    p2 = p3; //ok! p2 is a low-level const and p3 is a high and low level const.

}
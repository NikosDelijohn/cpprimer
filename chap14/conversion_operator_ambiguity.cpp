#include <iostream>

/*
A class defining constructors from or conversions to more than one 
arithmetic type can lead to ambiguity! For instance:

A is constructed from int but also from double AND
A is converted to int and also double. 

Hence, which version should we implicitly take to built-in convert to long double then?
Both are valid candidates!
*/

struct A
{
    A(int = 0);
    A(double);

    operator int() const;
    operator double() const;
};

void f(long double);

int main()
{
    A a;
    f(a);

    long lg;
    A a2(lg); // which constructor?? another ambiguity!

    return EXIT_SUCCESS;
}
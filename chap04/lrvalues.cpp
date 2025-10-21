#include <iostream>
#include "../help.hpp"

int main()
{
    /*
    Every expression is either an rvalue or an lvalue

    (C) L-values could stand on the lhs of an assignment 
    (C) R-values could not stand on the lhs of an assignment

    this doesn't translate well in C++. Things are more complicated. For instance
    we have l-values which can't be on the lhs of an assignment (consts).

    (C++) L-value means that we are using the object's identity (its location in memory)
    (C++) R-value means that we are using the object's value

    We can use an L-value when an R-value is required.
    We cannot use an R-value when an L-value is required!

    L and R values also impact the behavior of 'decltype'
    
    When decltype is applied to an expression (other than a variable) -> lvalue


    arithmetic operations -> return rvalues
    logical and relational opers -> return rvalues

    */

    int val = 42;
    int *p;
    decltype (*p) f = val; // f is an int& and not an int because the dereference operator yields an lvalue
    decltype (&p) g; // g is an int** and not an int**& because the address-of operator yields an rvalue

    return 0;
}
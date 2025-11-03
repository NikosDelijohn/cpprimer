#include <iostream>

typedef double money;

class A
{
public:
    typedef int money; // ok! no previous usage of money
    money val;
};

// This is allowed but this

class B
{
public:
    money val;
    typedef int money;
    money val_b; // is not ok! (unless compiling with -fpermissive) -> UB
    // Because class B allready has created a member (val) with the previous
    // definition of 'money'. Whereas in class 'A' there are declarations only
    // with the new definition of 'money'. So there is no type mixing involved in
    // the process.
};

// Hence, use definitions at the beginning of a class!
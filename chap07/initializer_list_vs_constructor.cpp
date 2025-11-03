#include <iostream>

class A
{
public:
    A(int);

private:
    const int some_int;
};

// This is allowed!
A::A(int value): some_int(value)
{}

class B
{
public:
    B(int);

private:
    const int some_int;
};

// This is not allowed!
B::B(int value)
{
    some_int = value;
}

// This is because the above is equal practically to:
/*

B::B(int value): some_int()
{
    some_int = value;
}

Hence the const attribute is already DEFAULT initialized. No changes can occur now to const.

Having a constructor body, is less performant than initializer list because the constructor 
body does twice the work. It default initializes an member, then creates a temporary object 
of the value type that has to be assigned and lastly does the assignment and destroys the 
temporary object. 

In an initializer list the work happens in place. The value is directly created and stored 
in the allocated memory for the member. 
*/
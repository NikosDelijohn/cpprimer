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

// Same for references
class C
{
public: 
    C(int);
private:
    int &iref;
};

// allowed!
C::C(int value): iref(value)
{}

// But this ... 

class D
{
public: 
    D(int);
private:
    int &iref;
};

// NOT allowed!
D::D(int value):
{
    iref = value;
}

// Same for members that DO NOT HAVE DEFAULT CONSTRUCTORS!

// The order of initialization for members is the order they are declared in the class
// not in the order the list initializers use them

class member_dependencies
{
public:
    member_dependencies():
        c(1), b(a+1), a(2){}
    // Don't be confused here, albeit the order
    // in which they are used here is c, b, a, the order
    // in which they will be initialized is a, b, c. Exactly 
    // as they are declared in line 94. Hence, its possible to initialize
    // b from a, but not the opposite, i.e., a from b.
private:
    int a, b, c;
};
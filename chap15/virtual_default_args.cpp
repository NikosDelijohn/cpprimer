#include <iostream>
using namespace std;

class Base {
public:
    virtual void foo(int x = 10) { cout << "Base: " << x << endl; }
};

class Derived : public Base {
public:
    void foo(int x = 20) override { cout << "Derived: " << x << endl; }
};

int main() 
{

    /* 
    
    It is only the STATIC type that determines which default argument 
    will be used for a virtual function. Thus, virtual functions should
    have the same valued default arguments.

    */

    Derived d;
    Base* b = &d;

    d.foo();  // Derived default 20
    b->foo(); // Base default 10 -> calls Derived body but uses Base default

    return EXIT_SUCCESS;
}
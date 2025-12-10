#include <iostream>

struct Base 
{
    Base() 
    { 
        std::cout << "Base ctor: calling foo() -> ";

        // Virtual call made *inside* Base constructor.
        // Dynamic dispatch is suppressed here.
        // Reason: during Base's construction, the Derived subobject
        // has not been constructed yet, so the dynamic type is BASE.
        // Therefore Base::foo is invoked.
        foo(); 
    }

    virtual ~Base() 
    {
        std::cout << "Base dtor: calling foo() -> ";

        // Virtual call made *inside* Base destructor.
        // Dynamic dispatch is also suppressed here.
        // Reason: during destruction, the Derived part has already been
        // destroyed, so the dynamic type has reverted to BASE.
        // Therefore Base::foo is invoked.
        foo();
    }

    virtual void foo() { std::cout << "Base::foo\n"; }
};

struct Derived : Base 
{
    int x = 42;   // Constructed *after* Base's constructor finishes.

    Derived() 
    {
        std::cout << "Derived ctor: calling foo() -> ";

        // Virtual call inside Derived constructor.
        // Now the Derived subobject *is* fully constructed,
        // so dynamic dispatch is active.
        // Therefore Derived::foo is invoked.
        foo();
    }

    ~Derived() override
    {
        std::cout << "Derived dtor: calling foo() -> ";

        // Virtual call inside Derived destructor.
        // The Derived subobject is still alive here,
        // so dynamic dispatch is active.
        // Therefore Derived::foo is invoked.
        foo();
    }

    virtual void foo() override 
    { 
        // Safe: x is fully constructed except when called from Base ctor/dtor.
        std::cout << "Derived::foo (x = " << x << ")\n"; 
    }
};

int main() 
{
    Derived d;  
    // Construction order:
    //   1. Base ctor runs → Base::foo
    //   2. Derived part constructed → Derived ctor → Derived::foo
    //
    // Destruction order (reverse):
    //   1. Derived dtor → Derived::foo
    //   2. Base dtor → Base::foo

    return EXIT_SUCCESS;
}

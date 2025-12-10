#include <iostream>
#include <string>

struct Base
{
    virtual void f(int);
    virtual void f(double);
    virtual void f(std::string);
};

struct Derived: Base 
{
    virtual void f(int) override;
};

struct Derived_Correctly: Base
{
    using Base::f; // Expose all publicly inherited Base overloads
    virtual void f(int) override;
};

int main()
{   
    Derived *derived;
    derived->f("STRING"); // ERROR, this version is hidden by f(int) now!

    /*
    The problem here is the following:

        1. The static type of the object (`Derived*`) determines which names are considered during
        compile-time name lookup. Only names visible in `Derived` are examined.

        2. The compiler finds the name `f` in `Derived`. It is declared virtual, so dynamic dispatch
        will be used once the function is selected.

        3. However, name lookup stops at `Derived`. Any functions named `f` in the base class (`Base`)
        are hidden by the declaration of `Derived::f(int)`. As a result, base-class overloads 
        such as `f(double)` and `f(std::string)` are not visible here, and the compiler cannot
        select a matching function.

        4. Dynamic dispatch only occurs after a valid function is found via name lookup. Since no
        matching overload is found in `Derived`, the call fails at compile time.
    */

    Derived_Correctly *c_derived;
    c_derived->f("STRING");

    /*
    
    The `using Base::f;` declaration in Derived_Correctly brings all base-class overloads
    of `f` into the derived class scope. Now, Derived_Correctly can override only the versions
    it needs (f(int)), while other overloads (f(double), f(string)) remain visible and callable.
    
    */
    
    return EXIT_SUCCESS;
}


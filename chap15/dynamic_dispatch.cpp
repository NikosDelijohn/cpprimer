#include <iostream>

struct Base
{
    // Virtual function: eligible for dynamic dispatch.
    virtual void f() const {
        std::cout << "Base::f\n";
    }

    void g() const {
        std::cout << "Base::g → calling f() → ";

        // Virtual call.
        // The dynamic type of *this determines which f() is chosen.
        // If *this is actually a Derived, Derived::f will run.
        f();
    }
};

struct Derived : Base
{
    // Override. Dynamic dispatch will choose this version
    // whenever the dynamic type of *this is Derived.
    void f() const override {
        std::cout << "Derived::f\n";
    }

    void g2() const {
        std::cout << "Derived::g2 → calling f() → ";

        // Also a virtual call. Since *this is a Derived,
        // this resolves to Derived::f.
        f();
    }
};

int main()
{
    Base p;      // dynamic type = Base
    Derived d;   // dynamic type = Derived

    // Calls Base::g. Inside g(), the virtual call f()
    // dispatches to Derived::f because the dynamic type is Derived.
    d.g();

    // Calls Derived::g2. The call to f() also dispatches
    // to Derived::f because the dynamic type is Derived.
    d.g2();

    Base *ptr = &p;
    // ptr points to a Base object; dynamic type = Base.
    // Base::g → f() resolves to Base::f.
    ptr->g();

    ptr = &d;
    // ptr points to a Derived object; dynamic type = Derived.
    // Base::g → f() now resolves to Derived::f.
    ptr->g();

    return EXIT_SUCCESS;
}
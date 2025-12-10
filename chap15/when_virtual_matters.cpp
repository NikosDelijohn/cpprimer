#include <iostream>
#include <string>

struct Base {
    // Virtual function
    virtual void virtualFunc() {
        std::cout << "Base::virtualFunc()\n";
    }

    // Non-virtual function
    void nonVirtualFunc() {
        std::cout << "Base::nonVirtualFunc()\n";
    }
};

struct Derived : Base {
    // Override virtual function
    void virtualFunc() override {
        std::cout << "Derived::virtualFunc()\n";
    }

    // Hides non-virtual function
    void nonVirtualFunc() {
        std::cout << "Derived::nonVirtualFunc()\n";
    }
};

int main() {
    // ---------------------------------------------------
    // 1. Direct objects (no pointer or reference)
    // ---------------------------------------------------
    Derived d;
    Base b;

    std::cout << "Direct object calls:\n";
    d.virtualFunc();       // Calls Derived::virtualFunc() -> static type = dynamic type = Derived
    d.nonVirtualFunc();    // Calls Derived::nonVirtualFunc() -> static type = dynamic type = Derived
    b.virtualFunc();       // Calls Base::virtualFunc() -> static type = dynamic type = Base
    b.nonVirtualFunc();    // Calls Base::nonVirtualFunc() -> static type = dynamic type = Base

    /*
        Key point:
        - No virtual mechanism is actually used here.
        - The compiler knows the exact type of each object at compile time.
        - Virtual keyword does not change behavior for direct objects.
    */

    // ---------------------------------------------------
    // 2. Access via pointer to base
    // ---------------------------------------------------
    Base* ptrBase = &d;

    std::cout << "\nPointer to base calls:\n";
    ptrBase->virtualFunc();    // Calls Derived::virtualFunc() -> dynamic dispatch used
    ptrBase->nonVirtualFunc(); // Calls Base::nonVirtualFunc() -> static call, no virtual dispatch

    /*
        Explanation:
        - Static type of ptrBase is Base*.
        - Dynamic type of object is Derived.
        - virtualFunc() is virtual -> vtable lookup chooses Derived::virtualFunc() at runtime.
        - nonVirtualFunc() is non-virtual -> Base::nonVirtualFunc() is called based on static type.
    */

    // ---------------------------------------------------
    // 3. Access via reference to base
    // ---------------------------------------------------
    Base& refBase = d;

    std::cout << "\nReference to base calls:\n";
    refBase.virtualFunc();    // Calls Derived::virtualFunc() -> dynamic dispatch used
    refBase.nonVirtualFunc(); // Calls Base::nonVirtualFunc() -> static call

    /*
        Explanation:
        - Same principle as pointer example.
        - Virtual functions dispatch according to dynamic type.
        - Non-virtual functions always dispatch according to static type.
    */

    return 0;
}
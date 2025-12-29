#include <iostream>
#include <string>

// ----------------------------
// Base / Derived hierarchy
// ----------------------------
struct Base {
    virtual ~Base() = default;
    virtual std::string name() const { return "Base"; }
};

struct Derived : Base {
    std::string extra = "derived state";
    std::string name() const override { return "Derived"; }
};

// ----------------------------
// Case 1: Return by VALUE (SLICING)
// ----------------------------
Base return_by_value() {
    Derived d;
    // d has Base subobject + Derived subobject
    return d;   // SLICING happens here
}

// ----------------------------
// Case 2: Return by REFERENCE (NO SLICING)
// ----------------------------
Base& return_by_reference(Base& b) {
    return b;   // refers to original object
}

// ----------------------------
// Case 3: Operator-style example (BAD)
// ----------------------------
struct CounterBase {
    int count = 0;
};

struct CounterDerived : CounterBase {
    int extra = 42;
};

// Postfix operator returning by value → slicing
CounterBase operator++(CounterBase& c, int) {
    CounterBase old = c; // copies only base
    ++c.count;
    return old;          // slicing if c is derived
}

// Prefix operator returning by reference → safe
CounterBase& operator++(CounterBase& c) {
    ++c.count;
    return c;            // no slicing
}

// ----------------------------
// main
// ----------------------------
int main() {
    std::cout << "=== Return by value ===\n";
    Base b1 = return_by_value();
    std::cout << b1.name() << "\n"; // prints "Base"

    std::cout << "\n=== Return by reference ===\n";
    Derived d;
    Base& b2 = return_by_reference(d);
    std::cout << b2.name() << "\n"; // prints "Derived"

    std::cout << "\n=== Operator slicing example ===\n";
    CounterDerived cd;
    cd.count = 10;

    CounterBase old = cd++; // postfix: slicing! cd.extra is lost in 'old'
    CounterBase* pold = &old;
    std::cout << "pold->count = " << pold->count << "\n";
    std::cout << "pold->extra is sliced off!\n";
    std::cout << "cd.count  = " << cd.count << "\n";


    ++cd; // prefix: no slicing
    std::cout << "after prefix ++, cd.count = " << cd.count << "\n";
    std::cout << "after prefix ++, cd.extra = " << cd.extra << "\n";
    return 0;
}

/*
Summary:

1. Returning a BASE by VALUE slices off the derived part.
2. Returning by REFERENCE preserves the dynamic type.
3. Postfix operators must return by value → dangerous for polymorphic types.
4. Prefix operators can return by reference → no slicing.
*/
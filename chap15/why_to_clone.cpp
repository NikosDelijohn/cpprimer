#include <iostream>
#include <memory>
#include <vector>

/*
Usage of polymorphism requires either pointers or references.
So especially when containers come into the mix, storing typically is best
to happen using (smart) pointers to base as element type.

However, to simplify code we typically define auxilary classes that hide the 
pointer usage, making it easier to the user to use our code. 

*/
class Base
{
public:
    Base() = default;
    Base(int x) : value(x) {}
    virtual ~Base() = default;

    // Virtual function for demonstration
    virtual void show() const
    {
        // Shows only Base data
        std::cout << "Base value: " << value << "\n";
    }

    // clone interface: returns a pointer to a heap-allocated *copy*
    // of the dynamic type of this object.
    virtual Base* clone() const &
    {
        // Copy a Base
        return new Base(*this);
    }

    virtual Base* clone() &&
    {
        // Move a Base
        return new Base(std::move(*this));
    }

protected:
    int value = 0;
};

class Derived : public Base
{
public:
    Derived(int x, int y) : Base(x), extra(y) {}

    // Override to show polymorphic behavior
    void show() const override
    {
        std::cout << "Derived value: " << value
                  << ", extra: " << extra << "\n";
    }

    // clone: IMPORTANT — copies/moves as Derived, not Base
    Derived* clone() const & override
    {
        return new Derived(*this);
    }

    Derived* clone() && override
    {
        return new Derived(std::move(*this));
    }

private:
    int extra = 0; // Additional data not present in Base
};

int main()
{
    // A container of shared_ptr<Base>
    std::vector<std::shared_ptr<Base>> basket;

    Derived d1(10, 99);
    Derived d2(20, 42);

    //
    // BAD SECTION — SLICING
    //
    // These lines construct a Base from a Derived object.
    // make_shared<Base>(d1) performs a Base copy constructor call:
    //       Base(const Base&)  <-- Derived part is discarded.
    //
    // The shared_ptr<Base> is fine, but the object *inside* it
    // is not Derived anymore → slicing occurs.
    //
    basket.push_back(std::make_shared<Base>(d1));
    basket.push_back(std::make_shared<Base>(d2));

    std::cout << "BAD basket:\n";
    for (auto& item : basket)
        item->show(); // Calls Base::show because the objects are Base

    //
    // GOOD SECTION — USING clone()
    //
    // clone() preserves the dynamic type:
    // d1.clone() returns new Derived(d1)
    //
    // We wrap that pointer in shared_ptr<Base>.
    //
    basket.clear();  

    // Unlike the earlier (bad) version that always created `Base` objects
    // (causing slicing), using clone() delegates object creation to the
    // dynamic type. Because clone() is virtual, the call:
    //      d1.clone()
    // dispatches to Derived::clone() when d1 is a Derived.
    // Thus each push_back stores a Base pointer to a freshly allocated
    // object of the correct dynamic type, avoiding slicing entirely.
    basket.push_back(std::shared_ptr<Base>(d1.clone()));
    basket.push_back(std::shared_ptr<Base>(d2.clone()));

    std::cout << "\nGOOD basket:\n";
    for (auto& item : basket)
        item->show(); // Calls Derived::show because the objects are Derived

    return 0;
}
#include <iostream>
#include <string>

/*
    A class containing at least 1 pure virtual function is an abstract class.
    Abstact classes cannot be instantiated. They are used solely through their
    derived classes.
*/

// -----------------------------------------------------------------------------
// 1. Base class: Quote
//    Simple example base class for pricing books.
// -----------------------------------------------------------------------------
class Quote {
public:
    Quote() {
        std::cout << "Quote() default constructor invoked\n";
    }

    Quote(const std::string& book, double price)
        : bookNo(book), price(price) {
        std::cout << "Quote(book, price) constructor invoked\n";
    }

    virtual ~Quote() = default;

    virtual double net_price(std::size_t n) const {
        return n * price;
    }

protected:
    std::string bookNo;
    double price = 0.0;
};

// -----------------------------------------------------------------------------
// 2. Abstract class: Disc_quote
//    Contains a pure virtual function, so it cannot be instantiated.
//    Demonstrates constructor chaining.
// -----------------------------------------------------------------------------
class Disc_quote : public Quote {
public:
    Disc_quote() {
        std::cout << "Disc_quote() default constructor invoked\n";
    }

    Disc_quote(const std::string& book, double price,
               std::size_t qty, double disc)
        : Quote(book, price), quantity(qty), discount(disc) {
        std::cout << "Disc_quote(book, price, qty, disc) constructor invoked\n";
    }

    // Pure virtual function keeps this class abstract
    virtual double net_price(std::size_t) const = 0;

protected:
    std::size_t quantity = 0;
    double discount = 0.0;
};

// -----------------------------------------------------------------------------
// 3. Example of defining a pure virtual function outside the class.
//    This is legal and sometimes required:
// A. When the base class constructor or destructor calls the pure virtual function.
// B. When you want to provide a common implementation for derived classes to reuse via Base::function().
//    This can be done e.g., through qualified calls like Base::func() from the derived class.
// -----------------------------------------------------------------------------
class BaseWithPure {
public:
    BaseWithPure() {
        std::cout << "BaseWithPure() constructor: calling f()...\n";
        f();
    }

    virtual ~BaseWithPure() = default;

    // Pure virtual function but still may have a definition
    virtual void f() = 0;
};

void BaseWithPure::f() {
    std::cout << "BaseWithPure::f() implementation called\n";
}

// -----------------------------------------------------------------------------
// 4. Example derived class overriding pure virtual function
// -----------------------------------------------------------------------------
class DerivedFromPure : public BaseWithPure {
public:
    DerivedFromPure() {
        std::cout << "DerivedFromPure() constructor invoked\n";
    }

    void f() override {
        std::cout << "DerivedFromPure::f() implementation called\n";
    }
};

// -----------------------------------------------------------------------------
// 5. Concrete derived class from Disc_quote demonstrating default construction
//    and constructor chaining.
// -----------------------------------------------------------------------------
class Bulk_quote : public Disc_quote {
public:
    Bulk_quote() {
        std::cout << "Bulk_quote() default constructor invoked\n";
    }

    Bulk_quote(const std::string& book, double price,
               std::size_t qty, double disc)
        : Disc_quote(book, price, qty, disc) {
        std::cout << "Bulk_quote(book, price, qty, disc) constructor invoked\n";
    }

    double net_price(std::size_t n) const override {
        if (n >= quantity)
            return n * price * (1 - discount);
        return n * price;
    }
};

// -----------------------------------------------------------------------------
// 6. Main demonstrates:
//    - Attempting to instantiate an abstract class (commented out)
//    - Constructor chaining through Quote -> Disc_quote -> Bulk_quote
//    - Calling defined pure virtual function from constructor
// -----------------------------------------------------------------------------
int main() {
    std::cout << "--- Demonstrating constructor chaining ---\n";
    Bulk_quote bq_default;

    std::cout << "\n--- Demonstrating parameterized constructor ---\n";
    Bulk_quote bq_param("12345", 50.0, 10, 0.2);

    std::cout << "\n--- Demonstrating pure virtual function with definition ---\n";
    DerivedFromPure d;
    d.f();

    // Illegal: cannot instantiate an abstract class
    // Disc_quote dq; // Uncommenting this line will cause a compile-time error

    return 0;
}

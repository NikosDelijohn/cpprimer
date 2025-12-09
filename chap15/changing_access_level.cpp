#include <iostream>

class Base 
{
public:
    void greet() { std::cout << "Hello from Base\n"; }
protected:
    int prot_val = 42;
};

class Derived : private Base 
{
public:
    // Promote specific Base members to Derived's public interface
    // Although we inherited as private, we can change the access level
    // to future classes that will inherit from this. 
    using Base::greet;
    using Base::prot_val;
};

class Third : public Derived {
public:
    void show() {
        greet();           // works: greet promoted to public in Derived
        std::cout << prot_val << "\n"; // works: prot_val promoted
    }
};

int main() 
{
    Third t;
    t.show();   // Output: "Hello from Base" and "42"

    t.greet();  // works because we promoted greet via `using`
    std::cout << t.prot_val << "\n"; // works because prot_val promoted
}
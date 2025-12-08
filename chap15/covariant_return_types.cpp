#include <iostream>

class Base
{
public: 
    Base() = default;
    virtual ~Base() = default;

    virtual Base* foo() {std::cout << "Hi from Base\n"; return this;}
};

class Derived: public Base
{
public:
    Derived() = default;
    virtual ~Derived() = default;

    virtual Derived* foo() override {std::cout << "Hi from Derived\n"; return this;}
};

class Derived2: public Base
{
public:
    Derived2() = default;
    virtual ~Derived2() = default;

    virtual Derived* foo() override {std::cout << "Hi from Derived2\n"; return new Derived;}
};

int main()
{
    /*
    Covariance, refers to covariant return type of VIRTUAL functions. A derived class,
    may override a virtual function & return a more-derived pointer or reference  type
    than the base version.
    
    Allowed ONLY for return types of virtual functions that are references or pointers
    to class types.
    */

    Base* b = new Derived2();
    Base* r = b->foo();  // returns Derived*, implicitly converted to Base* due to derived-to-base conversion
}
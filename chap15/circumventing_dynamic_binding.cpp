#include <iostream>

class Base {
public:
    virtual void foo() { std::cout << "Base::foo\n"; }
};

class Derived : public Base {
public:
    void foo() override { std::cout << "Derived::foo\n"; }

};

int main()
{
    Derived d;
    Base* b = &d;

    b->foo();        // dynamic dispatch → Derived::foo
    
    b->Base::foo();  // ***static call*** → Base::foo
    //b->Derived::foo(); // not possible, static type is what matters here! hence this won't compile, b has a static type of Base
    // and Base is not derived from Derived. Whereas the opposite is OK!

    Derived* dd;
    dd->Derived::foo(); // Ok! 
    dd->Base::foo(); // This is OK Derived is also Base type!

    // Note that this is all allowed due to the fact that the type of inheritance is public!
    // Usercode would not be able to do any sort of derived-to-base conversion otherwise!

    return EXIT_SUCCESS;
}
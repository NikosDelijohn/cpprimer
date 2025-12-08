#include <iostream>

class Base {
public:
    virtual void foo() { std::cout << "Base::foo\n"; }
};

class Derived : public Base {
public:
    void foo() override { std::cout << "Derived::foo\n"; }

    void test()
    {
        foo();          // dynamic binding → calls Derived::foo
        Base::foo();    // static binding  → calls Base::foo
    }
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

    d.test();        // shows both behaviors
}
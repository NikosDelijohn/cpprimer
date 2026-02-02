#include <iostream>

// Common base class
struct Base
{
    int value;
    Base() : value(0) {}
};

// Two classes that inherit Base *virtually*
struct A1 : public virtual Base
{
    void setFromA1(int v) { value = v; }
};

struct A2 : public virtual Base
{
    void setFromA2(int v) { value = v; }
};

// Diamond: D has A1 and A2, which both share ONE Base
struct D : public A1, public A2
{
    void print() const { std::cout << "Base::value = " << value << '\n'; }
};

int main()
{
    D obj;

    obj.A1::setFromA1(10);
    obj.print();   // 10

    obj.A2::setFromA2(42);
    obj.print();   // 42

    // No ambiguity due to virtual inheritance.
    // There is exactly one shared Base subobject in D,
    // so there is only one Base::value to refer to.
    // Without virtual inheritance, D would contain two
    // separate Base subobjects and this access would be
    // ambiguous, requiring qualification such as
    //   obj.A1::Base::value  or  obj.A2::Base::value.
    std::cout << obj.value << std::endl;


    // ---- CAST EXPLANATION ----

    // static_cast<A1&>(obj)
    //  - Does NOT create an A1 object.
    //  - It creates a reference bound to the A1 *subobject inside obj*.
    //  - Internally: pointer adjustment to the A1 part of D.

    A1& a1ref = static_cast<A1&>(obj);

    // static_cast<A2&>(obj)
    //  - Same idea: reference to the A2 subobject inside obj.

    A2& a2ref = static_cast<A2&>(obj);

    // Now we take the address of Base::value through each path.
    // Because Base is a *virtual base*, both paths point to the SAME Base.

    std::cout << "Address via A1 path: " << &a1ref.value << '\n';
    std::cout << "Address via A2 path: " << &a2ref.value << '\n';

    // The two printed addresses are identical:
    //  - a1ref.value -> Base::value via A1 -> virtual Base
    //  - a2ref.value -> Base::value via A2 -> same virtual Base
}

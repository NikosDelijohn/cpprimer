#include <iostream>

class Base
{
public:
    Base(int a, int b = 42)
    {
        std::cout << "Base constructor called with a=" << a << ", b=" << b << "\n";
    }

    Base(const Base& other)
    {
        std::cout << "Base copy constructor called\n";
    }

    Base(Base&& other) noexcept
    {
        std::cout << "Base move constructor called\n";
    }

    Base& operator=(const Base& rhs)
    {
        std::cout << "Base copy assignment called\n";
        return *this;
    }

    Base& operator=(Base&& rhs) noexcept
    {
        std::cout << "Base move assignment called\n";
        return *this;
    }
};

class Derived : public Base
{
public:
    /*
    Exceptions to inheriting constructors:
        1) If a derived class defines a constructor with the same parameters as 
           a constructor in the base, then that constructor is NOT inherited. The
           one defined in the derived class is used in its place
        2) The default constructor, copy constructors and move constructors are NOT
           inherited. Also, an inherited constructor is not considered as a user-defined
           constructor. Hence, a class that contains ONLY inherited constructors, will also
           have a default constructor
    */
    using Base::Base;  // inherit constructors
};

int main()
{
    Derived d1(10);      // calls Base(10, 42)
    Derived d2(10, 99);  // calls Base(10, 99)


    // CAREFUL:
    // -------
    // But although they are not inherited, the compiler can still
    // synthesize them if required to do so. However, by synthesizing
    // them, the sub-object part of Derived that is Base, must be copied/moved
    // by Base's move and copy ctor. Hence, the a delegating call will
    // be issued to Base. This is not to be confused that the base copy/move 
    // constructors were inherited!!!
    Derived d3(d1);       
    Derived d4(std::move(d2));

    return EXIT_SUCCESS;
}
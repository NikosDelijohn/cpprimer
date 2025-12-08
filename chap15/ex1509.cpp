#include <iostream>
#include <vector>

class Base
{
public:
    Base() = default;
    virtual ~Base() = default;
};

class Derived: public Base
{
public:
    Derived() = default;
    virtual ~Derived() = default;
};

int main()
{
    // case 1 ptr to base
    Base *ptr; 
    ptr = new Derived();

    // case 2 ref to base
    Base &rbase = *(new Derived()); //returns a pointer to a heap object, which when dereferenced is an lvalue.

    // case 3 containers
    std::vector<Base*> vec;
    vec.push_back(new Base());
    vec.push_back(new Derived());

    for (auto &ptr: vec)
        delete ptr;

    delete &rbase;

    delete ptr;

    return EXIT_SUCCESS;
}
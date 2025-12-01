#include <iostream>
#include <utility>
#include <algorithm>
#include <string>
#include <vector>

/*
    Reference qualifiers on member functions let you control whether 
    a function can be called on lvalue or rvalue objects.

    A member function qualified with & can only be called on lvalues. It 
    ensures that the object is not a temporary and is safe to modify or use without moving from.

    A member function qualified with && can only be called on rvalues (temporaries).
    This allows the function to safely modify the object in place, often enabling move semantics for efficiency.

    They let you tailor member function behavior depending on the value category of the object,
    enabling optimizations like in-place modification for temporaries while preserving safety for lvalues.

*/
class Foo
{
public:
    Foo(std::vector<int> v) : data(std::move(v)) {}

    // Lvalue-qualified: called on lvalues, const prevents in-place modification
    
    /*
    
    This prevents inplace modifications. So in an example where we have a named object

        Foo a({1,2,3});

    And we call:    

        Foo b = a.sorted(); 
    
    It will invoke the const & ovearload because a is an L-value. The benefit here
    is that the object a will not be altered. Instead a sorted copy will be returned 

    */

    Foo sorted() const & 
    {
#ifndef NDEBUG
        std::cout << __func__ << " const & version invoked\n";
#endif

        Foo copy(*this); // make a copy
        std::sort(copy.data.begin(), copy.data.end());

        return copy; // return sorted copy
    }

    // Rvalue-qualified: called on temporaries, safe to modify in place
    
    /*
    
    On the other hand, this is invoked on temporary objects that are going to be shortly destroyed.
    Hence, in-place modification is safe No one else is going to use this object.
    
        Foo a = Foo({3,5,-5}).sorted();
                ^^^^^^^^^^^^^
                r-value
    
    So, the object is modified in place and then assigned to a.
    
    */
    Foo sorted() && 
    {
#ifndef NDEBUG
        std::cout << __func__ << " && version invoked\n";
#endif
        // Sort In-place!
        std::sort(data.begin(), data.end());
        return *this;
    }

    void print() const 
    {
        for (auto n : data) std::cout << n << " ";
    }

private:
    std::vector<int> data;
};

Foo rvalue()
{
    return Foo({});
}

Foo global_foo({3,-1,0,2,-4});
Foo& lvalue()
{
    return global_foo;
}

int main()
{   

    Foo a({4,1,6,3,2,100,});
    Foo b = a.sorted();

    std::cout << "[object a]: "; a.print(); std::cout << "(unmodified)" << std::endl; 
    std::cout << "[object b]: "; b.print(); std::cout << std::endl; 

    std::cout << "[rvalue object]: ";
    Foo({10,9,8,5,6}).sorted().print();
    std::cout << "(modified in-place)\n";

    Foo c = Foo({10,9,8,5,6}).sorted();
    std::cout << "[object c]: "; c.print(); std::cout << std::endl; 

    rvalue().sorted();
    lvalue().sorted();

    return EXIT_SUCCESS;
}
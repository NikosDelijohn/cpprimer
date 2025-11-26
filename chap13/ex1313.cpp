#include <iostream>
#include <vector>

class X
{
public:
    X() { std::cout << "ctor X()" << std::endl;}
    ~X() { std::cout << "dtor ~X()" << std::endl;}

    X(const X&) { std::cout << "cctor X(const X&)" << std::endl;}
    
    X& operator=(const X &other) { std::cout << "copy-assignment X& operator=(const X &other)" << std::endl; return *this;}
};

void foo(X obj) {}

int main()
{
    // Constructors
    std::cout <<"\n --- Constructors --- \n";
    std::cout << "a: ";
    X a;

    std::cout << "b: ";
    X b = X(); 
    // Note: X b() does not create an object! Most-Vexing Parse -> creates a function

    std::cout <<"c: ";
    X c = {};

    std::cout <<"d: ";
    X d{};

    std::cout <<"\n --- Copy Constructors --- \n";
    // Copy Constructors
    std::cout << "ca: ";
    X ca = a;

    std::cout << "cb: ";
    X cb(b);

    std::cout << "cc: ";
    X cc{c};

    std::cout << "cd: ";
    X cd = {d};

    std::cout <<"\n --- Copy-Assignment --- \n";
    // Assignment operator
    std::cout << "ca = a: ";
    ca = a;

    
    std::cout <<"\n --- Pass by Value -> Copy Constructors & Destructor --- \n";
    // Function pass-by-val
    std::cout << "foo(b): ";
    foo(b);

    std::cout <<"\n --- Containers --- \n";
    // Containers
    std::vector<X> vec;

    std::cout << "vec.push_back(a): ";
    vec.push_back(a);
    
    std::cout << "vec.emplace_back(): ";
    vec.emplace_back();

    /*
    Note: Containers may need to re-allocate their memory. In that case,
    the objects are copied to a new memory address and the original objects
    are destroyed! So copy ctor and dtor calls may occur during the vector
    filling.

        When vector capacity is not enough:

        1 - Vector allocates new memory (usually larger than current size)
        2 - It moves or copies all existing elements to the new memory
        3 - If the class has no move constructor, it uses copy constructor
            3.1 - Old elements are destroyed → destructor calls appear
    */

    std::cout <<"\n --- Destructors --- \n";

    return EXIT_SUCCESS;
}
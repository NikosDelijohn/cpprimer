#include <iostream>
#include <memory>

struct Base 
{
    // Virtual destructor ensures that when deleting an object of a derived type
    // through a Base pointer (or a smart pointer to Base), the destructor of the
    // most derived class is called first, followed by Base's destructor.
    // This prevents resource leaks in derived classes.
    virtual ~Base() 
    { 
        std::cout << "Base destroyed\n"; 
    }
};

struct Derived : Base 
{
    int* arr;

    Derived() 
    { 
        arr = new int[10]; // manually allocate some heap resource
    }

    virtual ~Derived() override  
    { 
        // Free resources that are manually managed by Derived
        delete[] arr; 

        std::cout << "Derived destroyed\n"; 
    }
};

int main() 
{
    // Using a smart pointer to Base, but storing a Derived object
    std::unique_ptr<Base> ptr = std::make_unique<Derived>();

    /*
        Why virtual destructor is essential here:

        1. The type of 'ptr' is std::unique_ptr<Base>, so when it goes out of scope,
           it will call 'delete' on a Base* pointer internally.

        2. If Base::~Base were NOT virtual:
            - Only Base's destructor would run.
            - Derived::~Derived() would NOT be called.
            - The dynamically allocated array 'arr' in Derived would leak.
            - Also, executing delete on a pointer to base that points to a derived object is UB!

        3. Since Base::~Base IS virtual:
            - Derived::~Derived() is called first, cleaning up Derived's resources.
            - Then Base::~Base() is called.
            - Smart pointer safely deletes the object with full cleanup.
    */

    return EXIT_SUCCESS;
}

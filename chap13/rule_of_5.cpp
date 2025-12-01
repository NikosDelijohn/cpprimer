#include <iostream>

/*
    This class manually manages a dynamic int (allocated with `new`).
    Because it owns a raw resource, it must follow:

    - Rule of Three:
        * Destructor
        * Copy Constructor
        * Copy Assignment Operator

    - Rule of Five (C++11+):
        * + Move Constructor
        * + Move Assignment Operator

*/

/*

MOVE Semantics:

    For built-in types such as int, double, or raw pointers, “moving” an object has no real  semantic effect: 
    these types are trivially copyable, so applying std::move or using an rvalue reference simply  results in
    a bitwise copy of the object. There is no resource ownership to transfer, no  heap  allocations to steal, 
    and no optimization beyond what a normal copy would do. In contrast, for user-defined types like  string,
    std::vector, std::unique_ptr, or custom classes that manage dynamic resources, move  semantics allow  the 
    efficient transfer of ownership of internal resources. A move constructor or move assignment can  “steal” 
    memory or other expensive-to-copy data from the source object,  leaving  it  in  a  valid but unspecified
    state, while avoiding unnecessary deep copies or allocations. Thus, for built-in types, moves are trivial
    and  equivalent  to  copies,  whereas for types managing resources, moves provide significant performance 
    benefits.

*/

class Resource
{
public:
    // --------------------------------------------------------------
    // Default constructor
    // --------------------------------------------------------------
    Resource(int value = 0)
        : ptr(new int(value))
    {
        std::cout << "Default ctor: allocating *ptr = " << *ptr << "\n";
    }

    // --------------------------------------------------------------
    // Destructor  (Rule of Three)
    // --------------------------------------------------------------
    ~Resource()
    {
        std::cout << "Destructor: deleting ptr\n";
        delete ptr;
    }

    // --------------------------------------------------------------
    // Copy Constructor  (Rule of Three)
    // Performs a *deep copy* of the resource
    // --------------------------------------------------------------
    Resource(const Resource& other)
        : ptr(new int(*other.ptr))     // allocate NEW memory
    {
        std::cout << "Copy ctor: deep-copying *ptr = " << *ptr << "\n";
    }

    // --------------------------------------------------------------
    // Copy Assignment Operator  (Rule of Three)
    // Must handle self-assignment and deep copy
    // --------------------------------------------------------------
    Resource& operator=(const Resource& rhs)
    {
        std::cout << "Copy assignment\n";

        if (this != &rhs)  // protect against self-assignment
        {
            // Free old resource
            delete ptr;

            // Allocate new
            ptr = new int(*rhs.ptr);
        }
        return *this;
    }

    // --------------------------------------------------------------
    // Move Constructor  (Rule of Five)
    // Transfers ownership; leaves source in valid empty state
    // --------------------------------------------------------------
    Resource(Resource&& other) noexcept
        : ptr(other.ptr)
    {
        other.ptr = nullptr;  // prevent double delete
        std::cout << "Move ctor: taking ownership\n";
    }

    // --------------------------------------------------------------
    // Move Assignment Operator  (Rule of Five)
    // Transfers ownership and frees old resource
    // --------------------------------------------------------------
    Resource& operator=(Resource&& rhs) noexcept
    {
        std::cout << "Move assignment\n";

        if (this != &rhs)
        {
            delete ptr;        // free current resource
            ptr = rhs.ptr;     // steal
            rhs.ptr = nullptr; // avoid deleting twice
        }
        return *this;
    }

    // Helper: print stored value
    void print() const
    {
        std::cout << "Value = " << *ptr << "\n";
    }

private:
    int* ptr;  // raw pointer → requires Rule of Three/Five
};


int main()
{
    std::cout << "\n--- Creating a Resource r1 ---\n";
    Resource r1(10);

    std::cout << "\n--- Copy constructing r2 from r1 ---\n";
    Resource r2 = r1;   // calls copy constructor

    std::cout << "\n--- Copy assigning r3 from r1 ---\n";
    Resource r3(0);
    r3 = r1;            // calls copy assignment

    std::cout << "\n--- Move constructing r4 from temporary ---\n";
    Resource r4 = Resource(99);  // calls move constructor

    std::cout << "\n--- Move assigning r3 from temporary ---\n";
    r3 = Resource(500);          // calls move assignment

    std::cout << "\n--- End of main; destructors run automatically ---\n";
    
    return EXIT_SUCCESS;
}

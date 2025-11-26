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

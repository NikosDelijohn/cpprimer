#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>

//
// Value-like class: owns its resource -> swap is beneficial
//
class ValueLikePtr {
public:
    // Constructor
    ValueLikePtr(const std::string& s = "")
        : ps(new std::string(s))
    {
        std::cout << "ValueLikePtr ctor\n";
    }

    // Copy constructor (deep copy)
    ValueLikePtr(const ValueLikePtr& other)
        : ps(new std::string(*other.ps))
    {
        std::cout << "ValueLikePtr deep copy ctor\n";
    }

    // Destructor
    ~ValueLikePtr() {
        delete ps;
        std::cout << "ValueLikePtr dtor\n";
    }

    // Copy-assignment using **copy-and-swap**
    ValueLikePtr& operator=(ValueLikePtr rhs) { // pass by value -> copy ctor
        swap(*this, rhs);                        // cheap pointer swap
        return *this;
    } // rhs is destroyed !

    // Friend swap: swaps pointers, not string contents
    friend void swap(ValueLikePtr& a, ValueLikePtr& b) {
        std::cout << "swap(ValueLikePtr) -> cheap pointer swap\n";
        using std::swap;        // enable ADL
        swap(a.ps, b.ps);       // swap ownership (O(1))
    }

private:
    std::string* ps;  // owns its string
};


//
// Shared-like class: reference-counted -> swap is NOT beneficial
//
class SharedPtrLike {
public:
    SharedPtrLike(const std::string& s = "")
        : ps(new std::string(s)), use(new size_t(1))
    {
        std::cout << "SharedPtrLike ctor\n";
    }

    // Shallow copy: increment reference count
    SharedPtrLike(const SharedPtrLike& other)
        : ps(other.ps), use(other.use)
    {
        ++*use;
        std::cout << "SharedPtrLike shallow copy ctor\n";
    }

    // Assignment: shallow, cheap
    SharedPtrLike& operator=(const SharedPtrLike& rhs) {
        std::cout << "SharedPtrLike assignment (shallow)\n";
        if (this != &rhs) {
            if (!--*use) {
                delete ps;
                delete use;
            }
            ps  = rhs.ps;
            use = rhs.use;
            ++*use;
        }
        return *this;
    }

    ~SharedPtrLike() {
        if (!--*use) {
            delete ps;
            delete use;
        }
        std::cout << "SharedPtrLike dtor\n";
    }

    // Swap has **no real performance advantage**
    friend void swap(SharedPtrLike& a, SharedPtrLike& b) {
        std::cout << "swap(SharedPtrLike) -> no real benefit\n";
        using std::swap;
        swap(a.ps, b.ps);
        swap(a.use, b.use);
    }

private:
    std::string* ps; // shared ownership
    size_t* use;     // reference count
};
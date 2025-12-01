#include <iostream>
#include <string>
#include <utility>

class HasPtr
{
    std::string* ps;
    int i;

public:
    HasPtr(const std::string& s = "") : ps(new std::string(s)), i(0) {}
    HasPtr(const HasPtr& other) : ps(new std::string(*other.ps)), i(other.i) {}
    HasPtr(HasPtr&& other) noexcept : ps(other.ps), i(other.i) { other.ps = nullptr; }
    ~HasPtr() { delete ps; }

    // copy-and-swap assignment
    HasPtr& operator=(HasPtr rhs)  // pass-by-value
    {
        std::cout << "copy-and-swap assignment called\n";
        swap(*this, rhs);
        return *this;
    }

    // move-assignment
    HasPtr& operator=(HasPtr&& rhs) noexcept
    {
        std::cout << "move-assignment called\n";
        if (this != &rhs)
        {
            delete ps;
            ps = rhs.ps;
            i = rhs.i;
            rhs.ps = nullptr;
        }
        return *this;
    }

    friend void swap(HasPtr& a, HasPtr& b)
    {
        using std::swap;
        swap(a.ps, b.ps);
        swap(a.i, b.i);
    }
};

int main()
{
    HasPtr a("A"), b("B");

    a = b;                   // lvalue -> copy-and-swap
    a = HasPtr("temporary"); // ambiguous call. can use both copy-n-swap and move-assignment. because 
                             // copy-n-swap is pass-by-value, this implies that if the object is an lvalue
                             // we use copy-constructor, if it is an rvalue we use the move-constructor. So 
                             // it can be called. However, we also have a move-assignment that also matches

    return 0;
}
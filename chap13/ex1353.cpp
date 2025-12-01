#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <chrono>


class HasPtr1
{
    friend void swap(HasPtr1 &, HasPtr1 &);

public:
    HasPtr1(const std::string &s = std::string()):
        ps(new std::string(s)), i(0)
        {};
    HasPtr1(const char *cs) : ps(new std::string(cs)), i(0) {}
    HasPtr1(const HasPtr1 &other):
        ps(new std::string(*other.ps)), i(other.i){};
    /*
    Note: we cannot do ps(&std::string(*other.ps)) i.e., avoid using new
    due to the fact that after the scope of the ctor the string object
    will be destroyed and the freshly coppied object's ps pointer would
    remain dangling. The only way is to use new
    */
    HasPtr1(HasPtr1 &&other):
        ps(other.ps),
        i(other.i)
    {
        other.ps = nullptr;
    }

    ~HasPtr1()
    {
        delete ps;
    };

    /*
        Even for lvalue assignments, a temporary rhs is constructed (either via copy or move).
        This means extra memory allocation for the string pointer inside the temporary and extra constructor calls.

        Even when rhs is an rvalue, copy-and-swap still constructs a temporary and then swaps — instead of just transferring ownership, 
        we do more steps than necessary.
    */

    HasPtr1& operator=(HasPtr1 rhs)
    {
        if (this != &rhs) // the objects are different
        {
            swap(*this, rhs);
        }

        return *this;
    }

    bool operator<(const HasPtr1 &rhs)
    {
        return *ps < *rhs.ps;
    }

    std::string *ps;
    int i;
};

void swap(HasPtr1 &a, HasPtr1 &b)
{  
    using std::swap;
    swap(a.ps, b.ps);
    swap(a.i, b.i);
}

class HasPtr2
{

public:
    HasPtr2(const std::string &s = std::string()):
        ps(new std::string(s)), i(0)
        {};
    HasPtr2(const char *cs) : ps(new std::string(cs)), i(0) {}
    HasPtr2(const HasPtr2 &other):
        ps(new std::string(*other.ps)), i(other.i){};
    /*
    Note: we cannot do ps(&std::string(*other.ps)) i.e., avoid using new
    due to the fact that after the scope of the ctor the string object
    will be destroyed and the freshly coppied object's ps pointer would
    remain dangling. The only way is to use new
    */
    HasPtr2(HasPtr2 &&other):
        ps(other.ps),
        i(other.i)
    {
        other.ps = nullptr;
    }

    ~HasPtr2()
    {
        delete ps;
    };

    HasPtr2& operator=(HasPtr2 &rhs)
    {
        if (this != &rhs) // the objects are different
        {
            delete ps;

            ps = new std::string(*rhs.ps);
            i = rhs.i;
        }

        return *this;
    }

    HasPtr2& operator=(HasPtr2 &&rhs) noexcept
    {
        if (this != &rhs)
        {
            ps = rhs.ps;
            i = rhs.i;

            rhs.ps = nullptr;
        }

        return *this;
    }


    bool operator<(const HasPtr2 &rhs)
    {
        return *ps < *rhs.ps;
    }

    std::string *ps;
    int i;
};

int main()
{
    std::vector<HasPtr1> vec1;
    std::vector<HasPtr2> vec2;

    for (int i = 0; i < 1000000; ++i) {
        vec1.emplace_back("Test string");
        vec2.emplace_back("Test string");
    }

    // COPY ASSIGNMENT 
    auto start1 = std::chrono::high_resolution_clock::now();

    for (size_t i = 1; i < vec1.size(); ++i)
        vec1[i] = vec1[i-1]; // copy-and-swap

    auto end1 = std::chrono::high_resolution_clock::now();
    std::cout << "HasPtr1 copy-and-swap time: "
            << std::chrono::duration_cast<std::chrono::microseconds>(end1 - start1).count()
            << " us\n";

    // MOVE ASSIGNMENT
    auto start2 = std::chrono::high_resolution_clock::now();

    for (size_t i = 1; i < vec2.size(); ++i)
        vec2[i] = std::move(vec2[i-1]); // move-assignment

    auto end2 = std::chrono::high_resolution_clock::now();
    std::cout << "HasPtr2 move-assignment time: "
            << std::chrono::duration_cast<std::chrono::milliseconds>(end2 - start2).count()
            << " us\n";

    /*
      HasPtr1 copy-and-swap time: 39728 us
    HasPtr2 move-assignment time:  8176 us !!!
    */
    return EXIT_SUCCESS;
}
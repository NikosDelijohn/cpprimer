#include <iostream>
#include <string>

class HasPtr
{
public:
    HasPtr(const std::string &s = std::string()):
        ps(new std::string(s)), i(0), use(new std::size_t(1))
        {};
    HasPtr(const HasPtr &other):
        ps(other.ps), i(other.i), use(other.use)
    {
        ++*use;
    };

    ~HasPtr()
    {
        if (!--*use) // only if the use is 0 delete the instance's members.
        {
            std::cout << "Aight, time to say goodnight\n";
            delete ps;
            delete use;
        }
    };

    HasPtr& operator=(const HasPtr& rhs)
    {
        if (this != &rhs) // the objects are different
        {   
            if (!--*use)
            {
                std::cout << "Aight, time to say goodnight\n";
                delete ps;
                delete use;
            }

            ps = rhs.ps;             
            i = rhs.i;
            use = rhs.use;
            ++*use;
        }

        return *this;
    }

    std::string *ps;
    int i;

private:
    size_t *use;
};


int main()
{
    HasPtr A("Hi!");
    {
        HasPtr B(A);

        *A.ps = "Yes!"; // does modify B
        std::cout << *A.ps << " - vs - " << *B.ps << std::endl;
    } // B out of scope, but use count is 1 so no destructor action.

    HasPtr C("Hey");
    A = C; // This should destroy A's pointers copy-assign oper overload

    return EXIT_SUCCESS; // C destroyed. 
}
#include <iostream>
#include <string>

class HasPtr
{
    friend void swap(HasPtr &, HasPtr &);

public:
    HasPtr(const std::string &s = std::string()):
        ps(new std::string(s)), i(0)
        {};
    HasPtr(const HasPtr &other):
        ps(new std::string(*other.ps)), i(other.i){};

    /*
    Note: we cannot do ps(&std::string(*other.ps)) i.e., avoid using new
    due to the fact that after the scope of the ctor the string object
    will be destroyed and the freshly coppied object's ps pointer would
    remain dangling. The only way is to use new
    */

    ~HasPtr()
    {
        delete ps;
    };

    HasPtr& operator=(const HasPtr& rhs)
    {
        if (this != &rhs) // the objects are different
        {
            delete ps; // delete previous ps ptr! avoid memory leak
            
            ps = new std::string(*rhs.ps);             
            i = rhs.i;
        }

        return *this;
    }

    std::string *ps;
    int i;
};

void swap(HasPtr &a, HasPtr &b)
{  
    std::cout << "Swapping !\n";
    using std::swap;
    swap(a.ps, b.ps);
    swap(a.i, b.i);
}

int main()
{
    HasPtr A("Hi!");
    HasPtr B(A);

    *A.ps = "Yes!"; // doesn't modify B
    std::cout << *A.ps << " - vs - " << *B.ps << std::endl;
    swap(A,B);
    std::cout << *A.ps << " - vs - " << *B.ps << std::endl;


    return EXIT_SUCCESS;
}
#include <iostream>
#include <string>

class HasPtr
{
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
    HasPtr& operator=(const HasPtr& rhs)
    {
        if (this != &rhs) 
        {
            delete ps; // delete previous ps ptr! avoid memory leak
            
            ps = new std::string(*rhs.ps);             
            i = rhs.i;
        }

        return *this;
    }

private:
    std::string *ps;
    int i;

};


int main()
{
    return EXIT_SUCCESS;
}
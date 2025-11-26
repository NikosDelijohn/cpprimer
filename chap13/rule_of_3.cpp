#include <iostream>
#include <string>

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// If the class needs a destructor, it almost SURELY needs a copy constructor and copy-assignment operator as well! //
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class HasPtr
{
public:
    HasPtr(const std::string &s = std::string()):
        ps(new std::string(s)), i(0)
        {};

    ~HasPtr()
    {
        delete ps;
    };

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
        if (this != &rhs) // the objects are different
        {
            delete ps; // delete previous ps ptr! avoid memory leak
            
            ps = new std::string(*rhs.ps);             
            i = rhs.i;
        }

        return *this;
    }

    void set(std::string s) {*ps = s;}
    std::string get() {return *ps;}

private:
    std::string *ps;
    int i;

};

class WrongHasPtr
// Lets see what happens if we rely on synthesized (assignment-)copy methods 
{
public:
    WrongHasPtr(const std::string &s = std::string()):
        ps(new std::string(s)), i(0)
        {};
    ~WrongHasPtr()
    {
        delete ps;
    };

    void set(std::string s) {*ps = s;}
    std::string get() {return *ps;}

private:
    std::string *ps;
    int i;
};


int main()
{

    WrongHasPtr A("Hello There!");
    WrongHasPtr B(A); // The synthesized copy constructor will copy the pointer
    // Thus, we will have a SHALLOW copy, both pointers pointing to the same object

    std::cout << "A ptr -> " << A.get() << " - B ptr -> " << B.get() << std::endl;
    A.set("General Kenobi!");
    std::cout << "A ptr -> " << A.get() << " - B ptr -> " << B.get() << std::endl;
    
    /*
    So? What will happen when these objects are out of scope and must be Deleted?

    Object A will be deleted, and the pointer will be destroyed and freed
    Object B will be deleted, and the pointer, which points to the same pointee as A, will be destroyed and freed.

    Double free!!
    */

    // =========== VERSUS =========== // 

    HasPtr C("Howdy!");
    HasPtr D(C); // Our version of the copy constructor, will copy the pointee
    // Thus, we will have a DEEP copy, independent from the pointee of C.
    // Destructors delete their own memory safely

    std::cout << "C ptr -> " << C.get() << " - D ptr -> " << D.get() << std::endl;
    C.set("Partnur!");
    std::cout << "C ptr -> " << C.get() << " - D ptr -> " << D.get() << std::endl;
    
    return EXIT_SUCCESS; /* Brace for impact...crash due to double free is imminent!*/

}
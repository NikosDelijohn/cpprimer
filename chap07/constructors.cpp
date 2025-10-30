#include <iostream>
#include <string>

struct Sales_data
{
    std::string book_no;
    unsigned units_sold;
    double revenue;
};

struct Sales_data_with_constructors
{
    std::string book_no;
    unsigned units_sold = 0;
    double revenue = 0.0;

    Sales_data_with_constructors() = default; // = “Please generate the default constructor automatically — as if I hadn’t written any constructors myself.”
    Sales_data_with_constructors(const std::string &s): book_no(s) {}
    // This is a Constructor initializer list!
    // Specifies initial values for one or more data members of the object being created.

    Sales_data_with_constructors(const std::string &s, unsigned n, double p):
    units_sold(n), revenue(p*n) {book_no = s;}
    // This is still valid. However a minor performance comment needs to be done.
    /*
        For non-built-in types like std::string, in this constructor:

            units_sold(n), revenue(p*n) { book_no = s; }

        the following happens:
        1. book_no is first default-constructed before entering the constructor body.
        2. Then the copy assignment book_no = s overwrites it.

        This involves two steps: default construction + assignment.

        Versus using the initializer list:

            book_no(s), units_sold(n), revenue(p*n)

        Here, book_no is directly constructed using the copy constructor.
        No default construction occurs, so it’s more efficient.
            
    */
};

int main()
{
    Sales_data obj;
    // Default initialization. 
    // Well, it wasn't initialized at all really.
    // all besides book_no (string), which calls default constructor, is uninitialized!
    std::cout << obj.book_no << ' ' << obj.units_sold << ' ' << obj.revenue << std::endl;
    // a synthesized default constructor was added by the compiler that failed to find
    // any in-class initializer and thus it used default initialization for each member!

    Sales_data obj2{};
    // Value initialization
    // all values are value-initialized
    std::cout << obj2.book_no << ' ' << obj2.units_sold << ' ' << obj2.revenue << std::endl;
    // once again a synthesized default constructor was added by the compiler which however
    // value-initialized each of the members.

    Sales_data obj3 = {}; 
    // Value initialization, equivalent with obj2
    std::cout << obj3.book_no << ' ' << obj3.units_sold << ' ' << obj3.revenue << std::endl;

    Sales_data obj4(); // not a constructor call, but a function declaration, named obj4 that takes no arguments and returns a Sales_data object
    // To use Direct initialization, we always have to provide arguments! 

    Sales_data_with_constructors cobj;
    // Default initialization, similar to obj at line 22. 
    // BUT the synthesized default constructor finds in-class initializers and thus 
    // it correctly initializes the members.
    std::cout << cobj.book_no << ' ' << cobj.units_sold << ' ' << cobj.revenue << std::endl;

    Sales_data_with_constructors cobj2{};
    // Value initialization. The default constructor is called, and in-class initializers 
    // are applied for each member. Built-ins without in-class initializers would be zeroed.
    std::cout << cobj2.book_no << ' ' << cobj2.units_sold << ' ' << cobj2.revenue << std::endl;


    return 0;
}
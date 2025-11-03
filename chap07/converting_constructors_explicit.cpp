#include <iostream>
#include <string>
/*
A constructor that can be called with a single argument defines an 
IMPLICIT conversion from the constructor's parameter type to the class
type. However, we can prohibit the usage of such constructors for IMPLICIT
conversions by using the 'explicit' keyword as below.

*/

class Book
{
private:
    std::string book_title;
    int numbers_encountered = 0u;
public:
    Book() = default;
    explicit Book(std::string title): book_title(title) {
        #ifndef NDEBUG
        std::cout << __func__ << "Actual Explicit Constructor call!" << std::endl;
        #endif
    }
    explicit Book(const char* title): book_title(title) {
        #ifndef NDEBUG
        std::cout << __func__ << " Implicit Constructor call!" << std::endl;
        #endif
    }

    Book &combine(const Book &ref)
    {   
        if (book_title == ref.book_title)
            numbers_encountered += 1;
        return *this;
    }

    void print() const { 
        std::cout << book_title << " " << numbers_encountered << std::endl;
    }
};

int main()
{   
    std::string title = "Alice in Wonderland";
    Book book_a(title); 
    
    // In order to use combine now we have to explicitly
    // create an Object Book!
    book_a.combine(Book("Alice in Wonderland"));

    // book_a.combine("Alice in Wonderland"); // Implicit conversions are now prohibited! This statement is in error!
    // error: cannot convert ‘const char [20]’ to ‘const Book&’

    book_a.print(); // expect 1 !
    
    /* Explicit constructors can only be used for DIRECT initialization */
    //Book book_b = title; // Error Cannot copy-initialize either!
    //Book book_c = {title};
    Book book_d(title); // OK direct initialization!
    Book book_e{title};

    return EXIT_SUCCESS;
}


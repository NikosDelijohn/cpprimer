#include <iostream>
#include <string>
/*
A constructor that can be called with a single argument defines an 
IMPLICIT conversion from the constructor's parameter type to the class
type
*/

class Book
{
private:
    std::string book_title;
    int numbers_encountered = 0u;
public:
    Book() = default;
    Book(std::string title): book_title(title) {
        #ifndef NDEBUG
        std::cout << __func__ << " Explicit Constructor call!" << std::endl;
        #endif
    }
    Book(const char* title): book_title(title) {
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
    
    // The compiler generates a temporary object from the const char* we provided
    // and accepts the call to the function.
    book_a.combine("Alice in Wonderland");
    book_a.print(); // expect 1 !

    return EXIT_SUCCESS;
}


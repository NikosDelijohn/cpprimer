#include <iostream>
#include <string>

struct Book
{
    std::string book_title;
    std::string author;
    unsigned isbn;    

    Book() = default;
    Book(std::string title, std::string author, unsigned isbn):
        book_title(title),
        author(author),
        isbn(isbn)
    {}
    Book(std::string title, unsigned isbn):
        Book(title, "", isbn)
    {}
    Book(std::string title):
        Book(title, "", 0u)
    {}

    void print() const
    {
        std::cout << author << " wrote " << book_title << " which has ISBN-10 " << isbn << std::endl;
    }
};

int main()
{
    auto A = Book("Wizard of Oz");
    auto B = Book("The Black Tower", 1234512345);
    auto C = Book("Ithaca", "Kavafis", 123123123);

    A.print();
    B.print();
    C.print();

    return EXIT_SUCCESS;
}
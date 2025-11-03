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
        book_title(title),
        author(""),
        isbn(isbn)
    {}
    Book(std::string title):
        book_title(title),
        author(""),
        isbn()
    {}
};

int main()
{
    auto A = Book("Wizard of Oz");
    auto B = Book("The Black Tower", 1234512345);
    auto C = Book("Ithaca", "Kavafis", 123123123);

    return EXIT_SUCCESS;
}
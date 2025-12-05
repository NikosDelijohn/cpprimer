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

    explicit operator bool() const
    {                                               // ISBN should have format validation here 
        return !book_title.empty() || !author.empty() || isbn != 0;
    }
};

std::ostream& operator<<(std::ostream & out, const Book &book)
{
    out << book.author << ": " << book.book_title << " (" << book.isbn << ")" << std::ends;
    return out;
}

std::istream& operator>>(std::istream & in, Book &book)
{
    in >> book.author >> book.book_title >> book.isbn;
    
    if (!in)
        book = Book();

    return in;
}

bool operator==(const Book &a, const Book &b)
{
    return a.author == b.author 
        && a.book_title == b.book_title
        && a.isbn == b.isbn;
}

bool operator!=(const Book &a, const Book &b)
{
    return !(a == b);
}

int main()
{
    auto A = Book("Wizard of Oz");
    auto B = Book("The Black Tower", 1234512345);
    auto C = Book("Ithaca", "Kavafis", 123123123);

    std::cout << A << std::endl << B << std::endl << C << std::endl;

    std::cout << std::boolalpha << (A != B) << std::endl;

    return EXIT_SUCCESS;
}
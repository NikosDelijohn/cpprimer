#include <iostream>
#include <string>
#include <cassert>

using std::string;

// Forward Declarations
struct Sales_data;
std::istream &read(std::istream &, Sales_data &);
std::ostream &print(std::ostream &, const Sales_data &);
Sales_data add(const Sales_data &, const Sales_data &);

struct Sales_data
{
    std::string book_isbn;
    double total_revenue = 0.0;
    unsigned items_sold = 0;

    inline 
    Sales_data& combine(const Sales_data &other)
    {
        total_revenue += other.total_revenue;
        items_sold += other.items_sold;
        return *this;
    }

    inline
    string isbn() const
    {
        return book_isbn;
    }

    Sales_data() 
    {
        #ifndef NDEBUG
        std::cout << __func__ << ": Default constructor called!" << std::endl;
        #endif
    }
        
    Sales_data(std::istream &in)
    {
        #ifndef NDEBUG
        std::cout << __func__ << ": Constructor 2 called!" << std::endl;
        #endif
        read(in, *this);
    }

    Sales_data(const std::string &book_no, const unsigned items_sold, const double total_revenue):
        book_isbn(book_no), total_revenue(total_revenue), items_sold(items_sold) {
        #ifndef NDEBUG
        std::cout << __func__ << ": Constructor 3 called!" << std::endl;
        #endif
        }
    
    Sales_data(const std::string &book_no): book_isbn(book_no) {
        #ifndef NDEBUG
        std::cout << __func__ << ": Constructor 4 called!" << std::endl;
        #endif
    }

};

Sales_data add(const Sales_data &a, const Sales_data &b)
{
    Sales_data retval = a;
    retval.combine(b);
    return retval;
}

std::istream &read(std::istream &in, Sales_data &to)
{
    double price_of_one;
    in >> to.book_isbn >> to.items_sold >> price_of_one;
    to.total_revenue = price_of_one * to.items_sold;
    return in;
}

std::ostream &print(std::ostream &out, const Sales_data &to)
{
    out << to.book_isbn << ", sold " << to.items_sold << " copies for a total of " << to.total_revenue << " €" << std::endl;
    return out;
} 

int main()
{

    Sales_data total(std::cin);
    Sales_data trans(std::cin);
    
    while(std::cin)
    {
        if (total.isbn() == trans.isbn())
        {
            total.combine(trans);
        }
        else
        {
            print(std::cout, total) << std::endl;
            total = trans;
        }

        read(std::cin, trans);
    }
    print(std::cout, total) << std::endl;

    return EXIT_SUCCESS;
}
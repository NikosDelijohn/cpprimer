#include "sales_data.hpp"

using std::string;

Sales_data::Sales_data(const std::string &book_no, const unsigned items_sold, const double total_revenue):
    book_isbn(book_no), 
    total_revenue(total_revenue), 
    items_sold(items_sold) 
{
    #ifndef NDEBUG
    std::cout << __func__ << ": Delegator body called!" << std::endl;
    #endif
}

Sales_data::Sales_data(): Sales_data("", 0u, 0.0)
{
    #ifndef NDEBUG
    std::cout << __func__ << ": Constructor 1 body called!" << std::endl;
    #endif
}

Sales_data::Sales_data(std::istream &in):
    Sales_data("", 0u, 0.0)
{
    #ifndef NDEBUG
    std::cout << __func__ << ": Constructor 2 body called!" << std::endl;
    #endif

    operator>>(in, *this);
}

Sales_data::Sales_data(const std::string &book_no): 
    Sales_data(book_no, 0u, 0.0)
{
        #ifndef NDEBUG
        std::cout << __func__ << ": Constructor 3 body called!" << std::endl;
        #endif
}

Sales_data& Sales_data::operator=(const std::string &other_isbn)
{
    book_isbn = other_isbn;
    return *this;
}

std::istream &operator>>(std::istream &is, Sales_data &obj)
{
    double price_of_one;

    is >> obj.book_isbn >> obj.items_sold >> price_of_one;
    if(is)
        obj.total_revenue = price_of_one * obj.items_sold;
    else
        obj = Sales_data();

    return is;
}

#ifndef EX1421
Sales_data& Sales_data::operator+=(const Sales_data &other)
{
    if (isbn() == other.isbn())
    {
        total_revenue += other.total_revenue;
        items_sold += other.items_sold;
    }

    return *this;
}

Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data retval = lhs;
    retval += rhs;
    return retval;
}

#else

Sales_data& Sales_data::operator+=(const Sales_data &other)
{
    if (isbn() == other.isbn())
    {
       *this = *this + other;
    }

    return *this;
}

Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data retval = lhs;

    if (lhs.isbn() == rhs.isbn())
    {
        retval.total_revenue += rhs.total_revenue;
        retval.items_sold += rhs.items_sold;
    }
    return retval;
}
#endif

bool operator==(const Sales_data &lhs, const Sales_data &rhs)
{
    return lhs.book_isbn == rhs.book_isbn 
        && lhs.items_sold == rhs.items_sold
        && lhs.total_revenue == rhs.total_revenue;
}

bool operator!=(const Sales_data &lhs, const Sales_data &rhs)
{
    return !(lhs == rhs);
}

std::ostream& operator<<(std::ostream &os, const Sales_data &obj)
{
    os <<  obj.book_isbn << ", sold " 
        << obj.items_sold << " copies for a total of "
        << obj.total_revenue << " €. Average price: " 
        << obj.avg_price() << std::ends;

    return os;
}
#include "ex721.hpp"

using std::string;

Sales_data::Sales_data() = default;
Sales_data::Sales_data(std::istream &in)
{
    #ifndef NDEBUG
    std::cout << __func__ << ": Constructor 2 called!" << std::endl;
    #endif
    read(in, *this);
}

Sales_data::Sales_data(const std::string &book_no, const unsigned items_sold, const double total_revenue):
    book_isbn(book_no), 
    total_revenue(total_revenue), 
    items_sold(items_sold) 
{
    #ifndef NDEBUG
    std::cout << __func__ << ": Constructor 3 called!" << std::endl;
    #endif
}

Sales_data::Sales_data(const std::string &book_no): 
book_isbn(book_no) 
{
        #ifndef NDEBUG
        std::cout << __func__ << ": Constructor 4 called!" << std::endl;
        #endif
}

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
    out << to.book_isbn << ", sold " 
        << to.items_sold << " copies for a total of "
        << to.total_revenue << " €. Average price: " 
        << to.avg_price() << std::endl;
    return out;
}
#include <iostream>
#include <string>
#include <cassert>

using std::string;

struct Sales_data
{
    std::string book_isbn;
    double total_revenue;
    unsigned items_sold;

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
    Sales_data total;

    if (read(std::cin, total))
    {
        Sales_data transaction;
        while(read(std::cin, transaction))
        {
            if (total.isbn() == transaction.isbn())
            {
                #ifndef NDEBUG
                std::cout << __LINE__ << ": Matching ISBNs" << std::endl;
                #endif
                total = add(total, transaction);

            }
            else
            {
                print(std::cout, total) << std::endl;
                total = transaction;
            }
        }
        print(std::cout, total) << std::endl;
    }
    else 
    {
        std::cerr << "No data!?" << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
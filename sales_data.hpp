#pragma once

#include <iostream>
#include <string>
#include <cassert>

// ----------- FRIENDS -------------

class Sales_data; //forward declaration of class;

Sales_data add(const Sales_data &, const Sales_data &);
std::istream &read(std::istream &, Sales_data &);
std::ostream &print(std::ostream &, const Sales_data &);
std::istream &operator>>(std::istream &, Sales_data &);
std::ostream &operator<<(std::ostream &, const Sales_data &);
Sales_data operator+(const Sales_data &, const Sales_data &);
bool operator==(const Sales_data &, const Sales_data &);

class Sales_data
{

    friend std::istream &read(std::istream &, Sales_data &);
    friend std::ostream &print(std::ostream &, const Sales_data &);
    friend Sales_data add(const Sales_data &, const Sales_data &);

#ifdef _LEGACY_
    friend const std::string &LEGACY_isbn(Sales_data &);
    friend void LEGACY_combine(Sales_data &, Sales_data &);
#endif


public:

    Sales_data();    
    Sales_data(std::istream &);
    Sales_data(const std::string &, const unsigned, const double);
    Sales_data(const std::string &);
    
    inline Sales_data& combine(const Sales_data &other)
    {
        total_revenue += other.total_revenue;
        items_sold += other.items_sold;
        return *this;
    }
    
    inline std::string isbn() const { return book_isbn; }

private:

    inline double avg_price() const;

    std::string book_isbn;
    double total_revenue = 0.0;
    unsigned items_sold = 0;
};


/*
for inline specifics see ex722.hpp
*/

#ifdef _LEGACY_

inline
const std::string &LEGACY_isbn(Sales_data &item)
{ 
    return item.book_isbn;
}

inline
void LEGACY_combine(Sales_data &current, Sales_data &other)
{
    current.total_revenue += other.total_revenue;
    current.items_sold += other.items_sold;
}
#endif 

double Sales_data::avg_price() const
{
    // arithmetic conversion. int (items sold )must be converted to double
    return items_sold ? total_revenue/items_sold : 0.0;
}
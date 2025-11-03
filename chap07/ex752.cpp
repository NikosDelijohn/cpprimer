#include <iostream>
#include <string>

// Originally not an aggregate class. It had in class initializers
struct Sales_data
{
    std::string bookNo;
    // unsigned units_sold = 0;
    // double revenue = 0.0;
    unsigned units_sold;
    double revenue;
};

int main()
{
    Sales_data item = {"978-0590353403", 25, 15.99};
    std::cout << item.bookNo <<  ' ' << item.units_sold << ' ' << item.revenue << std::endl;

    return EXIT_SUCCESS;
}
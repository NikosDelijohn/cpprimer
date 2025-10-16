#include <iostream>

struct Sales_data {
    std::string bookNo;
    unsigned units_sold;
    double revenue;
};

void ex121 ()
{

    Sales_data data1, data2;
    double price_per_unit;
    std::cin >> data1.bookNo >> data1.units_sold >> price_per_unit;
    data1.revenue = price_per_unit * data1.units_sold;

    std::cin >> data2.bookNo >> data2.units_sold >> price_per_unit;
    data2.revenue = price_per_unit * data2.units_sold;

    std::cout << data1.bookNo << " " << data1.units_sold + data2.units_sold << " " << data1.revenue + data2.revenue
              << " " << (data1.revenue + data2.revenue) / (data1.units_sold + data2.units_sold) << std::endl; 
}

void ex122()
{
    Sales_data data1;
    double price_per_unit;

    double total_revenue{0.0};
    int total_items_sold(0);

    while (std::cin >> data1.bookNo >> data1.units_sold >> price_per_unit)
    {
        total_revenue += price_per_unit * data1.units_sold;
        total_items_sold += data1.units_sold;
    }

    std::cout << total_items_sold << " " << total_revenue << " " << total_revenue/total_items_sold << std::endl;

}

int main()
{
    ex121();
    ex122();
    // yada ...
    return 0;
}
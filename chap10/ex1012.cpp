#include <iostream>
#include <vector>
#include <algorithm>

#include "../sales_data.hpp"

bool compare_isbn(const Sales_data &a, const Sales_data &b)
{
    return a.isbn() < b.isbn();
}

int main()
{
    std::vector<Sales_data> items;

    Sales_data data_obj;
    while(read(std::cin, data_obj))
        items.push_back(data_obj);
    
    for (auto &sd: items)
        std::cout << sd.isbn() << " " << std::ends;
    std::cout << std::endl;
    
    std::sort(items.begin(), items.end(), compare_isbn);
    
    for (auto &sd: items)
        std::cout << sd.isbn() << " " << std::ends;
    std::cout << std::endl;   

    return EXIT_SUCCESS;
}
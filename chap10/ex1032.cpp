#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include "../sales_data.hpp"
#include <numeric>

int main()
{
    std::istream_iterator<Sales_data> input_iter(std::cin);
    std::istream_iterator<Sales_data> eof;
    
    std::vector<Sales_data> sales(input_iter, eof);
    std::vector<Sales_data> unique_sales;
    if (!sales.size())
    {
        std::cerr << "No Data?" << std::endl;
        return EXIT_FAILURE;
    }

    std::sort(sales.begin(), sales.end(), 
    [](const Sales_data &a, const Sales_data &b) -> bool
    {
        return a.isbn() < b.isbn();
    });

    std::unique_copy(sales.begin(), sales.end(), std::back_inserter(unique_sales));



    std::vector<Sales_data>::iterator prev = sales.begin();
    for(auto unique_sale = unique_sales.begin(); unique_sale != unique_sales.end(); ++unique_sale)
    {   

        auto curr = std::find_if(prev, sales.end(),
        [unique_sale](const Sales_data& obj) -> bool
        {
            return unique_sale->isbn() != obj.isbn();
        });   
        
        std::cout << std::accumulate(prev, curr, Sales_data(unique_sale->isbn()));
        
        prev = curr;
    }
    
    return EXIT_SUCCESS;
}
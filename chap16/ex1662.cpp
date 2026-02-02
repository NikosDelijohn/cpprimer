#include <unordered_map>
#include <string>
#include <iostream>
#include "../sales_data.hpp"

// compile with g++ ex1662.cpp ../sales_data.cpp

namespace std 
{

template<>
struct hash<Sales_data>
{
    using result_type = size_t;
    using argument_type = Sales_data;

    result_type operator()(const Sales_data&) const;
};

hash<Sales_data>::result_type hash<Sales_data>::operator()(const Sales_data& arg) const 
{
    std::cout << "hash<Sales_data> called\n";

    return hash<std::string>()(arg.isbn()) 
            ^ hash<double>()(arg.get_total_revenue())
            ^ hash<unsigned>()(arg.get_items_sold());

}

}

int main()
{
    std::unordered_map<Sales_data, int> umap; 

    Sales_data sd {"AAAA", 1, 2.0};

    umap.insert({sd,1});

    return EXIT_SUCCESS;
}
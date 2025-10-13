#include <iostream>
#include "Sales_item.h"

int main()
{
    
    Sales_item item_a, item_b;

    std::cin >> item_a >> item_b;
    
    std::cout << item_a + item_b;
    
    return 0;
}
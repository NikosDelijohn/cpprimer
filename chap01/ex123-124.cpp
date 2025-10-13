#include <iostream>
#include "Sales_item.h"

int main()
{
    
    Sales_item old_item, new_item;
    int transactions;
    
    if (std::cin >> old_item)
    {
        transactions = 1;
        while (std::cin >> new_item)
        {
            if (old_item.isbn() == new_item.isbn())
            {
                transactions += 1;
            }
            else
            {
                std::cout << "Total transactions of " << old_item << " --> " << transactions << std::endl;
                transactions = 1;
                old_item = new_item;
            }
        }
        std::cout << "Total transactions of " << old_item << " --> " << transactions << std::endl;
    }

    return 0;
}
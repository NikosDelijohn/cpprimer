#include "ex721.hpp"

int main()
{

    Sales_data total(std::cin);
    Sales_data trans(std::cin);
    
    while(std::cin)
    {
        if (total.isbn() == trans.isbn())
        {
            total.combine(trans);
        }
        else
        {
            print(std::cout, total) << std::endl;
            total = trans;
        }

        read(std::cin, trans);
    }
    print(std::cout, total) << std::endl;

    return EXIT_SUCCESS;
}
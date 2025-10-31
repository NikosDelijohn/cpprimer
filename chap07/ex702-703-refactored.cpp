#include "ex721.hpp"

using std::string;

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
                total.combine(transaction);

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
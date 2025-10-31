#define _LEGACY_ // must be defined before 721.hpp so the header is updated accordingly
#include "ex721.hpp"

// Compile with g++ ex701-refactored.cpp ex721.cpp

int main()
{
    Sales_data total;

    if (read(std::cin, total))
    {
        Sales_data transaction;
        while(read(std::cin, transaction))
        {
            if (LEGACY_isbn(total) == LEGACY_isbn(transaction))
            {
                #ifndef NDEBUG
                std::cout << __LINE__ << ": Matching ISBNs" << std::endl;
                #endif
                LEGACY_combine(total, transaction);

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
#include "ex722.hpp"

// compile with g++ ex722.cpp ex715-refactored.cpp

int main()
{
    Person Mike(std::cin);

    print(std::cout, Mike);

    return EXIT_SUCCESS;
}
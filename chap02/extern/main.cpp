#include <iostream>
#include "variable_declaration.hpp"

int main()
{
    std::cout << "pi = " << pi << " | buffer_size = " << buffer_size << " | elite yields: " << elite() << std::endl;
    return 0;

    // compile with g++ main.cpp variable_definition.cpp -o main
}
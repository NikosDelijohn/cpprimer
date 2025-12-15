#include <iostream>
#include <fstream>

#include "query.hpp"
#include "text_query.hpp"


int main()
{   

    std::ifstream input("input.txt");
    // ctor
    Text_Query tq(input);


    //std::cout << (Query("fiery") & Query("bird") | Query("wind")).eval(tq) << std::endl;
    std::cout << (Query("Daddy") ^ Query("hair")).eval(tq) << std::endl;

    return EXIT_SUCCESS;
}
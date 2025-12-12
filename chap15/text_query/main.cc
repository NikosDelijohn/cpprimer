#include <iostream>

#include "query.hpp"

int main()
{   
    Query q = Query("fiery") & Query("bird") | Query("wind");

    return EXIT_SUCCESS;
}
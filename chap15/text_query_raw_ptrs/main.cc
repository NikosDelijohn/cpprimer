#include <iostream>
#include <fstream>

#include "text_query.hpp"
#include "query_result.hpp"

int main()
{
    std::ifstream input("input.txt");
    
    std::cout << " TEXT QUERY \n";

    Text_Query tq(input);               // normal ctor
    auto tq_copy = tq;                  // copy ctor 
    auto tq_move = std::move(tq_copy);  // move ctor
    tq_copy = tq_move;                  // copy assignment
    tq_move = std::move(tq_copy);       // move assignment 

    std::cout << " QUERY RESULT \n";

    Query_Result res = tq.query("Daddy");
    auto qr_copy = res;
    auto qr_move = std::move(qr_copy);
    qr_copy = qr_move; 
    qr_move = std::move(qr_copy);

    std::cout << qr_move << std::endl;

    return EXIT_SUCCESS;
}
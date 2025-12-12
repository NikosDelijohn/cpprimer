#include "or_query.hpp"

#include "query.hpp"
#include "query_result.hpp"

Or_Query::Or_Query(const Query &left, const Query &right):
    Binary_Query(left, right, "|") 
{
#ifndef NDEBUG
    std::cout << "Or_Query::" << __func__ <<  std::endl;
#endif         
}

Query_Result Or_Query::eval(const Text_Query &tq) const
{
#ifndef NDEBUG
    std::cout << "Or_Query::" << __func__  << std::endl;
#endif  
    return Query_Result();
}   
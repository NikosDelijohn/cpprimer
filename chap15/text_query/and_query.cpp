#include "and_query.hpp"

#include "query.hpp"
#include "query_result.hpp"


And_Query::And_Query(const Query &left, const Query &right):
    Binary_Query(left, right, "&")
{
#ifndef NDEBUG
    std::cout << "And_Query::" << __func__ << std::endl;
#endif    
}

Query_Result And_Query::eval(const Text_Query &tq) const
{
#ifndef NDEBUG
    std::cout << "And_Query::" << __func__  << std::endl;
#endif  
    return Query_Result();
}
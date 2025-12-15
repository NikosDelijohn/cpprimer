#include "and_query.hpp"

#include "query.hpp"
#include "query_result.hpp"

#include <algorithm>
#include <iterator>

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
    Query_Result lhs_result = lhs.eval(tq);
    Query_Result rhs_result = rhs.eval(tq);

    std::set<size_t> and_result;

    std::set_intersection(lhs_result.cbegin(), lhs_result.cend(),
                          rhs_result.cbegin(), rhs_result.cend(),
                          std::inserter(and_result, and_result.begin())
    );

    return Query_Result(rep(), std::make_shared<std::set<size_t>>(and_result), lhs_result.get_file());
}
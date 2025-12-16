#include "or_query.hpp"

#include "query.hpp"
#include "query_result.hpp"

#include <algorithm>
#include <iterator>


Or_Query::Or_Query(const Query &left, const Query &right):
    Binary_Query(left, right, "|") 
{
#ifndef NDEBUG
    std::cout << "Or_Query::" << __func__ <<  std::endl;
#endif         
}

Or_Query* Or_Query::clone() const
{
    return new Or_Query(*this);
}

Query_Result Or_Query::eval(const Text_Query &tq) const
{
    
#ifndef NDEBUG
    std::cout << "Or_Query::" << __func__  << std::endl;
#endif  
    
    Query_Result lhs_result = lhs.eval(tq);
    Query_Result rhs_result = rhs.eval(tq);

    std::set<size_t> or_result;

    std::set_union(lhs_result.cbegin(), lhs_result.cend(),
                   rhs_result.cbegin(), rhs_result.cend(),
                   std::inserter(or_result, or_result.begin())
    );

    return Query_Result(rep(), std::set<size_t>(or_result), lhs_result.get_file());

}   
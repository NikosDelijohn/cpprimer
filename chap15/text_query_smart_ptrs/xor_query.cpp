#include "xor_query.hpp"
#include "query_result.hpp"

#include <algorithm>
#include <iterator>

Xor_Query::Xor_Query(const Query &lhs, const Query &rhs):
    Binary_Query(lhs,rhs,"^")
{
#ifndef NDEBUG
    std::cout << "Xor_Query::" << __func__ <<  std::endl;
#endif         
}

Query_Result Xor_Query::eval(const Text_Query &tq) const
{
#ifndef NDEBUG
    std::cout << "Xor_Query::" << __func__ <<  std::endl;
#endif         
    Query_Result lhs_result = lhs.eval(tq);
    Query_Result rhs_result = rhs.eval(tq);

    std::set<size_t> xor_result;

    std::set_symmetric_difference(lhs_result.cbegin(), lhs_result.cend(),
                                  rhs_result.cbegin(), rhs_result.cend(),
                                  std::inserter(xor_result, xor_result.begin())
    );

    return Query_Result(rep(), std::make_shared<std::set<size_t>>(xor_result), lhs_result.get_file());
}

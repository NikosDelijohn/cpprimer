#include "binary_query.hpp"

Binary_Query::Binary_Query(const Query &l, const Query &r, const std::string &op):
    lhs(l), rhs(r), op(op)
{
#ifndef NDEBUG
    std::cout << "Binary_Query::" << __func__ << std::endl;
#endif    
}

std::string Binary_Query::rep() const
{
#ifndef NDEBUG
    std::cout << "Binary_Query::" << __func__ << std::endl;
#endif    
    return "(" + lhs.rep() + " " + op + " " + rhs.rep() + ")";
}

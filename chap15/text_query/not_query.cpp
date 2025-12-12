#include "not_query.hpp"


std::string Not_Query::rep() const
{
#ifndef NDEBUG
    std::cout << "Not_Query::" << __func__ << "(" << query.rep() << ")" << std::endl;
#endif    
        return "~(" + query.rep() + ")";
}

Not_Query::Not_Query(const Query &q): query(q) 
{
#ifndef NDEBUG
    std::cout << "Not_Query::" << __func__ << std::endl;
#endif  
}

Query_Result Not_Query::eval(const Text_Query &tq) const
{
#ifndef NDEBUG
    std::cout << "Not_Query::" << __func__  << std::endl;
#endif  
    return Query_Result();
}


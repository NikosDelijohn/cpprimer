#include "query.hpp"
#include "word_query.hpp"
#include "not_query.hpp"
#include "and_query.hpp"
#include "or_query.hpp"

Query::Query(const std::string &str): q(new Word_Query(str))
{
#ifndef NDEBUG
    std::cout << "Query::" << __func__ << "(" << str << ")" << std::endl;
#endif 
}

Query::Query(std::shared_ptr<Base_Query> query): q(query) 
{
#ifndef NDEBUG
    std::cout << "Query::" << __func__ << "(Base_Query ptr)" << std::endl;
#endif 
}    

std::string Query::rep() const
{
#ifndef NDEBUG
    std::cout << "Query::"<<__func__<< std::endl;
#endif 

    return q->rep();
}

Query_Result Query::eval(const Text_Query &tq) const 
{
#ifndef NDEBUG
    std::cout << "Query::"<<__func__<< std::endl;
#endif
    return q->eval(tq); 
}


/* OPERATORS */

std::ostream& operator<<(std::ostream& os, const Query &query)
{
    return os << query.rep();
}

Query operator~(const Query &q)
{
    return Query(std::shared_ptr<Base_Query>(new Not_Query(q)));
}

Query operator&(const Query &lhs, const Query &rhs)
{
    return Query(std::shared_ptr<Base_Query>(new And_Query(lhs, rhs)));
}

Query operator|(const Query &lhs, const Query &rhs)
{
    return Query(std::shared_ptr<Base_Query>(new Or_Query(lhs, rhs)));
}
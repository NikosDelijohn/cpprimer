#include "query.hpp"
#include "word_query.hpp"
#include "not_query.hpp"
#include "and_query.hpp"
#include "or_query.hpp"
#include "xor_query.hpp"
#include "text_query.hpp"
#include "query_result.hpp"

Query::Query(const std::string &str): q(new Word_Query(str))
{
#ifndef NDEBUG
    std::cout << "Query::" << __func__ << "(" << str << ")" << std::endl;
#endif 
}

Query::Query(Base_Query *query): 
    q(query->clone()) 
{
#ifndef NDEBUG
    std::cout << "Query::" << __func__ << "(Base_Query ptr)" << std::endl;
#endif
}    

Query::~Query()
{
    delete q;
}

Query::Query(const Query &other): q(other.q->clone())
{
#ifndef NDEBUG
    std::cout << "[COPY CONSTRUCTOR]" << __func__ << std::endl;
#endif 
}

Query::Query(Query &&other) noexcept: q(other.q)
{
#ifndef NDEBUG
    std::cout << "[MOVE CONSTRUCTOR]" << __func__ << std::endl;
#endif 
    other.q = nullptr;
}

Query& Query::operator=(const Query &rhs)
{
#ifndef NDEBUG
    std::cout << "[COPY ASSIGNMENT]" << __func__ << std::endl;
#endif

    if (this != &rhs)
    {
        delete q;    
        q = rhs.q->clone();
    }
    return *this;
}  

Query& Query::operator=(Query &&rhs) noexcept
{
#ifndef NDEBUG
    std::cout << "[MOVE ASSIGNMENT]" << __func__ << std::endl;
#endif

    if (this != &rhs)
    {
        delete q;    
        q = rhs.q;
        
        rhs.q = nullptr;
    }
    return *this;
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
    return Query(new Not_Query(q));
}

Query operator&(const Query &lhs, const Query &rhs)
{
    return Query(new And_Query(lhs, rhs));
}
Query operator|(const Query &lhs, const Query &rhs)
{
    return new Or_Query(lhs, rhs);
}

Query operator^(const Query &lhs, const Query &rhs)
{
    return new Xor_Query(lhs, rhs);
}

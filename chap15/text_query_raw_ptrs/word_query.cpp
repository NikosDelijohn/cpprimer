#include "word_query.hpp"
#include "query_result.hpp"

Word_Query::Word_Query(const std::string &str): query_word(str)
{
#ifndef NDEBUG
    std::cout << "WordQuery::" << __func__ << "(" << str << ")" << std::endl;
#endif 
}

Word_Query* Word_Query::clone() const
{
#ifndef NDEBUG
    std::cout << "WordQuery::" << __func__ << std::endl;
#endif
    return new Word_Query(*this);
}

Query_Result Word_Query::eval(const Text_Query &tq) const
{
#ifndef NDEBUG
    std::cout << "Word_Query::"<<__func__<< std::endl;
#endif 
    return tq.query(query_word);
}   

std::string Word_Query::rep() const
{
#ifndef NDEBUG
    std::cout << "Word_Query::"<<__func__<< " " << query_word << " " << std::endl;
#endif 
    return query_word;
}
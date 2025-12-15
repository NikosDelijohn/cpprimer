#include "not_query.hpp"

#include <algorithm>
#include <iterator>

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

    auto operand_result = query.eval(tq);

    std::set<size_t> all_lines;
    for (size_t idx = 0u; idx != operand_result.get_file()->size(); ++idx)
        all_lines.insert(idx);
    
    std::set<size_t> not_result;

    std::set_difference(all_lines.cbegin(), all_lines.cend(), operand_result.cbegin(), operand_result.cend(),
                        std::inserter(not_result, not_result.begin()));

    return Query_Result(rep(), std::make_shared<std::set<size_t>>(not_result), operand_result.get_file());
}


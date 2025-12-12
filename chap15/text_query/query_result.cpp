#include "query_result.hpp"

Query_Result::Query_Result(const std::string & sought, std::shared_ptr<std::set<size_t>> lines, std::shared_ptr<std::vector<std::string>> file):
    sought(sought), lines(lines), file(file)
{
#ifndef NDEBUG
    std::cout << "Query_Result::" << __func__ << "(" << sought << ", <set>, <sh_ptr>)" << std::endl;
#endif 
}
#include "query_result.hpp"
#include <sstream>

Query_Result::Query_Result(const std::string & sought, std::shared_ptr<std::set<size_t>> lines, std::shared_ptr<std::vector<std::string>> file):
    sought(sought), lines(lines), file(file)
{
#ifndef NDEBUG
    std::cout << "Query_Result::" << __func__ << "(" << sought << ", <set>, <sh_ptr>)" << std::endl;
#endif 
}

std::ostream& operator<<(std::ostream&out, const Query_Result &qr)
{
    out << "element " << qr.sought << " occurs " << qr.size() << " times.\n";

    for (auto &lineno: *qr.lines)
        out << "\t(line " << (lineno + 1) << ") " << qr.file->at(lineno) << std::endl;


    return out;
}
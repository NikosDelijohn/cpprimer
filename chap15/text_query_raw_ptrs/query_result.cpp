#include "query_result.hpp"
#include <sstream>

Query_Result::Query_Result(const std::string &sought, const std::set<size_t> &lines, const std::vector<std::string> &file):
    sought(sought),
    lines(new std::set<size_t>(lines)),
    file(new std::vector<std::string>(file))
{
#ifndef NDEBUG
    std::cout << "[CONSTRUCTOR]" << __func__ << "(" << sought << ", <set>, <sh_ptr>)" << std::endl;
#endif 
}

Query_Result::~Query_Result()
{
#ifndef NDEBUG
    std::cout << "[DESTRUCTOR]" << __func__ << std::endl;
#endif 
    delete lines;
    delete file;
}

Query_Result::Query_Result(const Query_Result &other):
    sought(other.sought),
    lines(new std::set<size_t>(*other.lines)),
    file(new std::vector<std::string>(*other.file))
{
#ifndef NDEBUG
    std::cout << "[COPY CONSTRUCTOR]" << __func__ << std::endl;
#endif 
}

Query_Result::Query_Result(Query_Result &&other) noexcept:
    sought(std::move(other.sought)),
    lines(other.lines),
    file(other.file)
{
#ifndef NDEBUG
    std::cout << "[MOVE CONSTRUCTOR]" << __func__ << std::endl;
#endif 
    other.lines = nullptr;
    other.file = nullptr;
}

Query_Result& Query_Result::operator=(const Query_Result &rhs)
{
#ifndef NDEBUG
    std::cout << "[COPY ASSIGNMENT]" << __func__ << std::endl;
#endif 
    if (this != &rhs)
    {
        sought = rhs.sought;
        lines = new std::set<size_t>(*rhs.lines);
        file = new std::vector<std::string>(*rhs.file);
    }
    return *this;
}

Query_Result& Query_Result::operator=(Query_Result &&rhs) noexcept
{
#ifndef NDEBUG
    std::cout << "[MOVE ASSIGNMENT]" << __func__ << std::endl;
#endif 
    if (this != &rhs)
    {
        delete lines;
        delete file;

        sought = std::move(rhs.sought);
        lines = rhs.lines;
        file = rhs.file;

        rhs.lines = nullptr;
        rhs.file  = nullptr;
    }
    return *this;
}

std::ostream& operator<<(std::ostream&out, const Query_Result &qr)
{
    out << "element " << qr.sought << " occurs " << qr.size() << " times.\n";

    for (auto &lineno: *qr.lines)
        out << "\t(line " << (lineno + 1) << ") " << qr.file->at(lineno) << std::endl;


    return out;
}
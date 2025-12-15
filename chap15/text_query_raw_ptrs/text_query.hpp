#pragma once 

#include <memory>
#include <vector>
#include <string>
#include <map>
#include <set>

#include "query_result.hpp"

class Text_Query
{
public:

    using line_no = std::vector<std::string>::size_type;
    Text_Query() = default;
    explicit Text_Query(std::ifstream&);
    ~Text_Query();
    Text_Query(const Text_Query &);
    Text_Query(Text_Query &&) noexcept;
    Text_Query& operator=(const Text_Query &);
    Text_Query& operator=(Text_Query &&) noexcept;

    Query_Result query(const std::string&) const;

    std::map<std::string, std::set<line_no>*> get_wm() { return wm; }
    
private:

    std::vector<std::string> *file;
    std::map<std::string, std::set<line_no>*> wm;    
};
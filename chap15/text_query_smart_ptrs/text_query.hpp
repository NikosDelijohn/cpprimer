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
    Query_Result query(const std::string&) const;

private:

    std::shared_ptr<std::vector<std::string>> file;
    std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;    
};
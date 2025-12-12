#pragma once 

#include <string>
#include <memory>
#include <set>
#include <vector>
#include <iostream>


class Query_Result
{
public:
    Query_Result() = default;
    Query_Result(const std::string &, std::shared_ptr<std::set<size_t>>, std::shared_ptr<std::vector<std::string>>);
    
private:
    std::string sought;
    std::shared_ptr<std::set<size_t>> lines;
    std::shared_ptr<std::vector<std::string>> file;
    
};
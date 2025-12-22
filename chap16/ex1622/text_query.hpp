#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <memory>
#include "deleter.hpp"

class Query_Result;

class Text_Query
{
public:
    Text_Query(std::ifstream& file);
    Query_Result query(const std::string&) const;

private:
    std::shared_ptr<std::vector<std::string>> file_contents;
    std::map<std::string, std::shared_ptr<std::set<size_t>>> word2line;
};
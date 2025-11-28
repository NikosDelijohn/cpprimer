#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <memory>

class Query_Result;
class strvec;

class Text_Query
{
public:
    Text_Query(std::ifstream& file);
    Query_Result query(const std::string&) const;

private:
    std::shared_ptr<strvec> file_contents;
    std::map<std::string, std::shared_ptr<std::set<size_t>>> word2line;
};
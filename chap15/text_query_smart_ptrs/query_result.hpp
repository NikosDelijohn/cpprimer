#pragma once 

#include <string>
#include <memory>
#include <set>
#include <vector>
#include <iostream>


class Query_Result
{   
    friend std::ostream& operator<<(std::ostream&, const Query_Result &);
    friend class And_Query;
    friend class Or_Query;
    friend class Xor_Query;
    friend class Not_Query;

public:

    Query_Result() = default;
    Query_Result(const std::string &, std::shared_ptr<std::set<size_t>>, std::shared_ptr<std::vector<std::string>>);

    std::set<size_t>::iterator cbegin() const { return lines->cbegin(); }
    std::set<size_t>::iterator cend() const { return lines->cend(); }

    std::shared_ptr<std::vector<std::string>> get_file() const { return file; }
    size_t size() const { return lines->size(); }
    
private:
    std::string sought;
    std::shared_ptr<std::set<size_t>> lines;
    std::shared_ptr<std::vector<std::string>> file;
    
};

std::ostream& operator<<(std::ostream&, const Query_Result &);
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
    Query_Result(const std::string &, const std::set<size_t>&, const std::vector<std::string> &);
    ~Query_Result();
    Query_Result(const Query_Result &);
    Query_Result(Query_Result &&) noexcept;
    Query_Result& operator=(const Query_Result &);
    Query_Result& operator=(Query_Result &&) noexcept;

    std::set<size_t>::iterator cbegin() const { return lines->cbegin(); }
    std::set<size_t>::iterator cend() const { return lines->cend(); }

    std::vector<std::string> get_file() const { return *file; }
    size_t size() const { return lines->size(); }
    
private:
    std::string sought;
    std::set<size_t> *lines;
    std::vector<std::string> *file;
    
};

std::ostream& operator<<(std::ostream&, const Query_Result &);
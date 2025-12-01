#pragma once 

#include <memory>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <sstream>

#include "strvec.hpp"

class Query_Result
{
    friend std::ostream &print(std::ostream &,const Query_Result &);
public:
    Query_Result(std::string word,
        std::shared_ptr<std::set<size_t>> lines,
        std::shared_ptr<strvec> file):
            result_word(word),
            lines(lines),
            file_contents(file)
    {};
    
private:

    std::string result_word;
    std::shared_ptr<std::set<size_t>> lines;
    std::shared_ptr<strvec> file_contents;

};

inline
std::ostream &print(std::ostream & out, const Query_Result &qr)
{
    size_t total_occurences = 0u;
    for (auto beg = qr.lines->cbegin(); beg != qr.lines->cend(); ++beg)
    {
        std::stringstream ss(*(qr.file_contents->begin() + *beg));
        std::string word;
        while (ss>>word)
            if(word == qr.result_word)
                ++total_occurences;        
    }

    out << "element " << qr.result_word << " occurs " << total_occurences << " times.\n";
    for (auto beg = qr.lines->cbegin(); beg != qr.lines->cend(); ++beg)
    {   
        out << "\t(line " << *beg + 1 << ") " << *(qr.file_contents->begin() + *beg) << std::endl;
    }

    return out;
}
#include <memory>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <sstream>

#include "string_blob.hpp"
#include "string_blob_ptr.hpp"

class Query_Result
{
    friend std::ostream &print(std::ostream &,const Query_Result &);
public:
    Query_Result(std::string word,
        std::shared_ptr<std::set<size_t>> lines,
        std::shared_ptr<String_Blob> file):
            result_word(word),
            lines(lines),
            file_contents(file)
    {};
    
private:

    std::string result_word;
    std::shared_ptr<std::set<size_t>> lines;
    std::shared_ptr<String_Blob> file_contents;

};

inline
std::ostream &print(std::ostream & out, const Query_Result &qr)
{
    size_t total_occurences = 0u;
    
    for (auto beg = qr.lines->cbegin(); beg != qr.lines->cend(); ++beg)
    {
        std::stringstream ss(String_Blob_Ptr(*qr.file_contents, *beg).dereference());
        std::string word;
        while (ss>>word)
            if(word == qr.result_word)
                ++total_occurences;        
        
    }

    out << "element " << qr.result_word << " occurs " << total_occurences << " times.\n";
    for (auto beg = qr.lines->cbegin(); beg != qr.lines->cend(); ++beg)
    {   
        out << "\t(line " << *beg + 1 << ") " << String_Blob_Ptr(*qr.file_contents, *beg).dereference() << std::endl;
    }

    return out;
}
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

    std::set<size_t>::iterator begin();
    std::set<size_t>::iterator end();

    std::shared_ptr<String_Blob> get_file() const;
    
private:

    std::string result_word;
    std::shared_ptr<std::set<size_t>> lines;
    std::shared_ptr<String_Blob> file_contents;

};

std::ostream &print(std::ostream &, const Query_Result &);

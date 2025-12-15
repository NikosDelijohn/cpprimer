#include "text_query.hpp"

#include <sstream>
#include <fstream>
#include <algorithm>


Text_Query::Text_Query(std::ifstream& source_file):
    file(std::make_shared<std::vector<std::string>>())
{   
    std::string line;
    std::string word;

    line_no line_number = 0;
    while(std::getline(source_file, line))
    {
        std::stringstream ss(line);
        while(ss >> word)
        {
            word.erase(std::remove_if(word.begin(), word.end(),
                                [](unsigned char c){ return std::ispunct(c); }),
                 word.end());

            auto it = wm.find(word);

            if (it == wm.end())
                wm[word] = std::make_shared<std::set<line_no>>(std::set<line_no>{line_number});
            else
                it->second->insert(line_number);
        }

        file->push_back(line);
        ++line_number;
    }
}

Query_Result Text_Query::query(const std::string& search) const
{   
#ifndef NDEBUG
    std::cout << "Text_Query::" << __func__ <<  std::endl;
#endif      
    static std::shared_ptr<std::set<size_t>> nodata = std::make_shared<std::set<size_t>>();

    auto find = wm.find(search);

    if (find == wm.end())
        return Query_Result(search, nodata, file);
    else
        return Query_Result(search, find->second, file);

}


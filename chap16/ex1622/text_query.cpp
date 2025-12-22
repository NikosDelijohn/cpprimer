#include <sstream>
#include "text_query.hpp"
#include "query_result.hpp"

Text_Query::Text_Query(std::ifstream& file):
file_contents(std::shared_ptr<std::vector<std::string>>(new std::vector<std::string>(), DebugDelete{}))
{
    std::string line;
    std::string word;
    
    size_t line_no = 0;

    while(std::getline(file, line))
    {   

        std::stringstream ss(line);

        while(ss >> word)
        {
            auto find_it = word2line.find(word);
            
            if(find_it == word2line.end())
            {
                //word2line[word] = std::make_shared<std::set<size_t>>(std::set<size_t>{line_no});
                word2line[word] = std::shared_ptr<std::set<size_t>>(new std::set<size_t>{line_no}, DebugDelete());
            }
            else
            {
                find_it->second->insert(line_no);
            }
        }   

        file_contents->push_back(line);
        ++line_no;
    }
}

Query_Result Text_Query::query(const std::string& str) const
{
    //static std::shared_ptr<std::set<size_t>> nodata = std::make_shared<std::set<size_t>>();
    static std::shared_ptr<std::set<size_t>> nodata(new std::set<size_t>{}, DebugDelete{});
    
    auto find_it = word2line.find(str); 
    if (find_it == word2line.end())
    {
        return Query_Result(str, nodata, file_contents);
    }
    else
    {
        return Query_Result(str, find_it->second, file_contents);
    }
}
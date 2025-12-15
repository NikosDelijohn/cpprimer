#include "text_query.hpp"

#include <sstream>
#include <fstream>
#include <algorithm>


Text_Query::Text_Query(std::ifstream& source_file):
    file(new std::vector<std::string>())
{  
#ifndef NDEBUG
    std::cout << "[CONSTRUCTOR]" << __func__ << "(std::ifstream& source_file)" << std::endl;
#endif
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
                wm[word] = new std::set<line_no>(std::set<line_no>{line_number});
            else
                it->second->insert(line_number);
        }

        file->push_back(line);
        ++line_number;
    }
}

Text_Query::~Text_Query()
{
#ifndef NDEBUG
    std::cout << "[DESTRUCTOR]" << __func__ << "()" << std::endl;
#endif

    delete file;
    for (const auto &pair: wm)
        delete pair.second;
}

Text_Query::Text_Query(const Text_Query &other):
    file(new std::vector<std::string>(*other.file))
{
#ifndef NDEBUG
    std::cout << "[COPY CONSTRUCTOR]" << __func__ << "(const Text_Query &)" << std::endl;
#endif
    for (const auto &pair: other.wm)
    {
        wm[pair.first] = new std::set<line_no>(*pair.second);
    }
}

Text_Query::Text_Query(Text_Query &&other) noexcept:
    file(other.file)
{
#ifndef NDEBUG
    std::cout << "[MOVE CONSTRUCTOR]" << __func__ << "(Text_Query &&)" << std::endl;
#endif
    for (auto &pair: other.wm)
    {
        wm[pair.first] = pair.second;
        pair.second = nullptr;
    }

    other.wm.clear();
    other.file = nullptr;
}

Text_Query& Text_Query::operator=(const Text_Query &rhs)
{
#ifndef NDEBUG
    std::cout << "[COPY ASSIGNMENT]" << __func__ << "(const Text_Query &)" << std::endl;
#endif
    if (this != &rhs)
    {
        delete file;
        for (const auto &this_pair: wm)
            delete this_pair.second;
        wm.clear();

        file = new std::vector<std::string>(*rhs.file);
        for (const auto &pair: rhs.wm)
            wm[pair.first] = new std::set<line_no>(*pair.second);
    }
    return *this;
}

Text_Query& Text_Query::operator=(Text_Query &&rhs) noexcept
{
#ifndef NDEBUG
    std::cout << "[MOVE ASSIGNMENT]" << __func__ << "(Text_Query &&)" << std::endl;
#endif
    if (this != &rhs)
    {
        delete file;
        for (const auto &this_pair: wm)
            delete this_pair.second;
        wm.clear();

        file = rhs.file;
        wm = rhs.wm;

        rhs.file = nullptr;
        for (auto &pair: rhs.wm)
            pair.second = nullptr;
        rhs.wm.clear();
    }
    return *this;
}

Query_Result Text_Query::query(const std::string& search) const
{   
#ifndef NDEBUG
    std::cout << "[MEMBER FUNC]" << "Text_Query::" << __func__ <<  std::endl;
#endif      
    static std::set<size_t> *nodata = new std::set<size_t>();

    auto find = wm.find(search);

    if (find == wm.end())
        return Query_Result(search, *nodata, *file);
    else
        return Query_Result(search, *find->second, *file);

}


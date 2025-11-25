#include "query_result.hpp"

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

std::set<size_t>::iterator Query_Result::begin()
{
    return lines->begin();
}

std::set<size_t>::iterator Query_Result::end()
{
    return lines->end();
}

std::shared_ptr<String_Blob> Query_Result::get_file() const
{
    return file_contents;
}
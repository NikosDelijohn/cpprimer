#include <memory>
#include <iostream>
#include <vector>
#include <string>
#include <set>

class Query_Result
{
public:
    Query_Result(std::string,
        std::shared_ptr<std::set<size_t>>,
        std::shared_ptr<std::vector<std::string>>);
    
private:

    std::string result_word;
    std::shared_ptr<std::set<size_t>> lines;
    std::shared_ptr<std::vector<std::string>> file_contents;

};
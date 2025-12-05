#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>

class in_to_out
{
public:
    std::string operator()(std::istream& stream)
    {
        std::string line;
        std::getline(stream, line);
        
        if(!stream)
            line = std::string();
        
        return line;
    }
};

int main()
{
    in_to_out i2o;

    std::vector<std::string> vecs;
    auto it = std::back_inserter<std::vector<std::string>>(vecs);

    std::string str;
    while (!(str = i2o(std::cin)).empty()) 
        *it = str;

    for(auto &elem: vecs)
        std::cout << elem << std::endl;

    return EXIT_SUCCESS;
}
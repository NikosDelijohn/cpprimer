#include <iostream>
#include <string>

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

    std::cout << i2o(std::cin) << std::endl;

    return EXIT_SUCCESS;
}
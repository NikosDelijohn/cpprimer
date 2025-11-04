#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << " filename.txt" << std::endl;
        return EXIT_FAILURE;
    }

    std::ifstream input_file;
    std::vector<std::string> file_contents;

    input_file.open(argv[1], std::ios::in);

    std::string line;
    while(getline(input_file, line))
    {
        std::cout << "Read: " << line << std::endl;
        file_contents.push_back(line);
    }
    
    for (const std::string &c: file_contents)
        std::cout << "Stored: " <<  c << std::endl;

    input_file.close();

    return EXIT_SUCCESS;
}
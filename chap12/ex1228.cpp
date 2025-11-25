#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <fstream>
#include <memory>
#include <sstream>

int main()
{
    std::ifstream file("ex1228-input.txt");

    std::map<std::string, std::set<size_t>> word2line;
    std::vector<std::string> file_contents;

    size_t line_no = 0;

    std::string line;   
    std::string word;

    // File Parsing
    while(std::getline(file, line))
    {   

        std::stringstream ss(line);

        while(ss >> word)
        {
            auto find_it = word2line.find(word);
            
            if(find_it == word2line.end())
            {
                word2line[word] = std::set<size_t>{line_no};
            }
            else
            {
                find_it->second.insert(line_no);
            }
        }   

        file_contents.push_back(line);
        ++line_no;
    }

    // Querying
    std::cout << R"(  ___ _  _     ___   ___  )" << std::endl;
    std::cout << R"( | _ \ \| |___/ _ \ / _ \ )" << std::endl;
    std::cout << R"( |   / .` (_-< (_) | (_) |)" << std::endl;
    std::cout << R"( |_|_\_|\_/__/\___/ \__\_\)" << std::endl;
    std::cout << " Really Not So Optimized Querying\n"
              << " v0. Type 'q' to Exit\n"
              << " ?> ";
    
    std::string sought;
    while (std::cin >> sought && (sought != "q"))
    {
        auto find_it = word2line.find(sought); 
        if (find_it == word2line.end())
        {
            std::cout << " Element not found in file." << std::endl;
        }
        else
        {
            size_t total_occurences = 0u;
            for (auto beg = find_it->second.cbegin(); beg != find_it->second.cend(); ++beg)
            {
                std::stringstream ss(file_contents[*beg]);
                std::string word;
                while (ss >>word)
                    if(word == sought)
                        ++total_occurences;        
            }

            std::cout << "element " << sought << " occurs " << total_occurences << " times.\n";
            for (auto beg = find_it->second.cbegin(); beg != find_it->second.cend(); ++beg)
            {   
                std::cout << "\t(line " << *beg + 1 << ") " << file_contents[*beg] << std::endl;
            }
        }   
    }

    std::cout << "Thank you for using RNsOQ. Adios!👋👋" << std::endl;

    return EXIT_SUCCESS;

}
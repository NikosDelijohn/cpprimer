#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>
#include <string>

int main()
{

    std::ifstream file("ex1029-input.txt");
    std::istream_iterator<std::string> source_iter(file);
    std::istream_iterator<std::string> eof;

    std::vector<std::string> data;
    std::back_insert_iterator<std::vector<std::string>> vec_back_iter(data); 

    std::copy(source_iter, eof, vec_back_iter);

    for (auto &elem: data) std::cout << elem << " " << std::ends; std::cout << std::endl;
    
    return EXIT_SUCCESS;

}
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

void print_vec(std::vector<std::string> &vec)
{
    for (auto &elem: vec)
        std::cout << elem << " ";
    std::cout << std::endl;
}

int main()
{
    std::vector<std::string> words = {"There", "are", "indeed", "are", "some", "some"};
    
    print_vec(words);

    std::sort(words.begin(), words.end());
    auto unique_end = std::unique(words.begin(), words.end());
    print_vec(words);

    words.erase(unique_end, words.end());
    print_vec(words);

    return EXIT_SUCCESS;
}
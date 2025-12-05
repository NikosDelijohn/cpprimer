#include <iostream>
#include <string>
#include <fstream>
#include <cstddef>

class range
{
public:
    range(size_t left = 0, size_t right = SIZE_MAX): a(left), b(right){}

    bool operator()(std::string str) { return !str.empty() && a <= str.length() && str.length() <= b;}

private:
    size_t a, b;
};

int main()
{
    std::ifstream input("lorem.txt");
    range one_to_ten(1,10);
    std::string word; 
    size_t cc = 0u;
    while(input >> word)
        if (one_to_ten(word)) ++cc;

    std::cout << "There are " << cc << " words in the range [0, 10]\n";

    return EXIT_SUCCESS;
}
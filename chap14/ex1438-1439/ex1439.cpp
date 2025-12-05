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
    range one_to_nine(1,9);
    range ten_or_more(10);

    std::string word; 
    size_t cc_1_to_9 = 0u;
    size_t cc_10_plus = 0u;
    while(input >> word)
    {
        if (one_to_nine(word)) ++cc_1_to_9;
        if (ten_or_more(word)) ++cc_10_plus;
    }

    std::cout << "There are " << cc_1_to_9 << " words in the range [0, 9]\n";
    std::cout << "There are " << cc_10_plus << " word ins the range [10 MAX]\n";

    return EXIT_SUCCESS;
}
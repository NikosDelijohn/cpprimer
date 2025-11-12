#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

void remove_duplicates(std::vector<std::string> &s_vec)
{
    std::sort(s_vec.begin(), s_vec.end());
    auto unique_end = std::unique(s_vec.begin(), s_vec.end());
    s_vec.erase(unique_end, s_vec.end());
}

bool is_shorter(const std::string &a, const std::string &b)
{
    return a.size() < b.size();
}

bool has_less_than(const std::string &str, const int &sz)
{
    return str.size() < sz;
}


void biggies(std::vector<std::string> words, std::vector<std::string>::size_type sz)
{
    remove_duplicates(words);
    std::stable_sort(words.begin(), words.end(), std::bind(is_shorter, std::placeholders::_1, std::placeholders::_2));

    auto num_of_words = std::count_if(words.begin(), words.end(),std::bind(has_less_than, std::placeholders::_1, sz));
    std::cout << "There are " << num_of_words << " word(s) of size less than " << sz  << std::endl;

}

int main()
{

    std::vector<std::string> words = {
        "apple", "zebra", "cat", "banana", "dog",
        "apple", "fig", "banana", "grape", "house"
    };

    biggies(words, 6);

}
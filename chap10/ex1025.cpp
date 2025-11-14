#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <algorithm>

void remove_duplicates(std::vector<std::string> &s_vec)
{
    std::sort(s_vec.begin(), s_vec.end());
    auto unique_end = std::unique(s_vec.begin(), s_vec.end());
    s_vec.erase(unique_end, s_vec.end());
}

bool check_size(const std::string& str, const int &sz)
{
    return str.size() >= sz;
}


void biggies(std::vector<std::string> words, std::vector<std::string>::size_type sz)
{
    remove_duplicates(words);
    std::stable_sort(words.begin(), words.end(),
        [](const std::string &a, const std::string &b)
        { 
            return a.size() < b.size();
        }
    );

    // returns an iterator to the first object for which the condition holds
    auto partition_end = std::partition(words.begin(), words.end(), std::bind(check_size, std::placeholders::_1, sz));

    std::vector<std::string>::difference_type num_of_words = partition_end - words.begin();

    std::cout << "There are " << num_of_words << " word(s) of size " << sz << " or bigger!" << std::endl;

}

int main()
{

    std::vector<std::string> words = {
        "apple", "zebra", "cat", "banana", "dog",
        "apple", "fig", "banana", "grape", "house"
    };

    biggies(words, 2);
    biggies(words, 3);
    biggies(words, 4);
    biggies(words, 5);

}
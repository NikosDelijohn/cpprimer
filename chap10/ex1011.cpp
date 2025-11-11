#include <iostream>
#include <vector>
#include <string>
#include <algorithm>



inline
bool is_shorter(const std::string &a, const std::string &b)
{
    return a.size() < b.size();
}

void print_vec(std::vector<std::string> &vec)
{
    for (auto &elem: vec)
        std::cout << elem << " ";
    std::cout << std::endl;
}

void eliminate_duplicates(std::vector<std::string> &vec)
{
    std::stable_sort(vec.begin(), vec.end(), is_shorter);
    auto end_unique = std::unique(vec.begin(), vec.end());
    vec.erase(end_unique, vec.end());
}

int main()
{
    std::vector<std::string> s_vec = {"aa", "aaa", "bb", "bbb", "cc" ,"cc", "ccc", "ddddd"};
    print_vec(s_vec);

    eliminate_duplicates(s_vec);
    print_vec(s_vec);

    return EXIT_SUCCESS;
}
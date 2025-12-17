#include <iostream>
#include <list>
#include <vector>
#include <string>

template <typename Iter, typename Value>
Iter find(Iter start, Iter end, const Value& sought)
{
    while(start != end)
        if (*start++ == sought)
            return --start;
    
    return end;
}

int main()
{
    std::list<std::string> list {"Now", "You", "See", "Me"};
    std::vector<std::string> vec {"Now", "You", "Don't"};

    auto res_list = find(list.begin(), list.end(), "See");
    auto res_vec = find(vec.begin(), vec.end(), "You");

    std::cout << *res_list << std::endl;
    std::cout << *res_vec << std::endl;

    res_list = find(list.begin(), list.end(), "404");
    std::cout <<  ((res_list == list.end()) ? "NOT FOUND" : *res_list) << std::endl;

    return EXIT_SUCCESS;
}
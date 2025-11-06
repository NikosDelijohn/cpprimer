#include <iostream>
#include <forward_list>
#include <string>

using std::forward_list;
using std::string;

void func(forward_list<string> &list, const string &first, const string &second)
{
    auto prev = list.before_begin();
    auto curr = list.begin();

    while (curr != list.end())
    {
        if (*curr == first)
        {
            curr = list.emplace_after(curr, second);
            break;
        }

        prev = curr;
        ++curr;
    }

    if (curr == list.end())
    {
        list.emplace_after(prev, second);
    }

}

int main()
{
    forward_list<string> a_list = {"Some", "random", "strings", "here", "no", "big", "deal."};

    func(a_list, "Some", "not so");
    func(a_list, "here", "and there");
    func(a_list, "ERROR 404", "Bye!");

    for (auto &str: a_list)
        std::cout << str << " " << std::ends;
    std::cout << std::endl;

    return EXIT_SUCCESS;
}
#include <iostream>
#include <list>
#include <vector>
#include <string>
using std::string;
using std::list;
using std::vector;

int main()
{

    list<const char*> l_chars = {"Hello", "C-style", "Strings"};
    vector<string> v_strings;
    v_strings.assign(l_chars.begin(), l_chars.end());

    for(auto &str: v_strings)
        std::cout << str << std::endl;

    return EXIT_SUCCESS;
}
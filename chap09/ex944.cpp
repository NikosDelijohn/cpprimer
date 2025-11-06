#include <iostream>
#include <string>

void repl(std::string &s, const std::string &_old, const std::string &_new)
{   

    for (std::string::size_type idx = 0u; idx < s.size(); ++idx)
    {   
        if (s.substr(idx, _old.size()) == _old)
        {
            s.replace(idx, _old.size(), _new);
        }
    } 

}

int main()
{

    std::string test_str = "Why tho? Even thru constant pain and thru hardships he prevailed! Why tho?";

    repl(test_str, "tho", "though");
    repl(test_str, "thru", "through");

    std::cout << test_str;

    return EXIT_SUCCESS;
}
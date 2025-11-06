#include <iostream>
#include <string>

// FML...
void repl(std::string &s, const std::string &_old, const std::string &_new)
{   
    auto prev = s.begin();
    auto curr = s.begin();
    
    while (curr != s.end())
    {
    
        prev = curr; 

        size_t matching_characters = 0u;
        for(auto o_iter = _old.begin(); o_iter != _old.end(); ++o_iter, ++curr)
        {
            if (*o_iter != *curr)
                break;

            ++matching_characters; 
        }

        if (matching_characters == _old.size())
        {   
            std::string::difference_type position = prev - s.begin();
            curr = s.erase(prev, curr);
            curr = s.insert(curr, _new.begin(), _new.end());
        }

        ++curr;
    }

}

int main()
{

    std::string test_str = "Why tho? Even thru constant pain and thru hardships he prevailed! Why tho?";

    repl(test_str, "tho", "though");
    repl(test_str, "thru", "through");

    std::cout << test_str << std::endl;

    return EXIT_SUCCESS;
}
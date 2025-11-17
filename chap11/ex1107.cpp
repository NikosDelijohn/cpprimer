#include <iostream>
#include <string>
#include <vector>
#include <map>

void add_member(std::map<std::string, std::vector<std::string>> &family,
    const std::string lastname,
    const std::initializer_list<std::string> children)
{
    family[lastname] = std::vector<std::string>(children);
}

void add_to_existing(std::map<std::string, std::vector<std::string>> &family, const std::string &lastname, const std::string &child)
{
    family[lastname].push_back(child);
}

int main()
{
    std::map<std::string, std::vector<std::string>> family;

    add_member(family, "Smithereen", {"Mary", "Jack", "Joe", "Daniel"});
    add_member(family, "Thorn", {"Larry", "Jessica", "Madelyn"});

    add_to_existing(family, "Thorn", "Joseph");

    for (const auto &pair: family)
    {
        std::cout << "Family " << pair.first << ": " << std::ends;

        for (auto &child: pair.second)
            std::cout << child <<  " " << std::ends;
        std::cout << std::endl;
    }


    return EXIT_SUCCESS;
}
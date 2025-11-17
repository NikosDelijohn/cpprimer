#include <iostream>
#include <string>
#include <vector>
#include <map>

void add_member(std::map<std::string, std::vector<std::pair<std::string, std::string>>> &family,
    const std::string lastname,
    const std::initializer_list<std::pair<std::string, std::string>> children)
{
    family[lastname] = std::vector<std::pair<std::string, std::string>>(children);
}

void add_to_existing(std::map<std::string, std::vector<std::pair<std::string, std::string>>> &family, const std::string &lastname, const std::string &child, const std::string &bday)
{
    family[lastname].emplace_back(child, bday);
}

int main()
{
    std::map<std::string, std::vector<std::pair<std::string, std::string>>> family;

    add_member(family, "Smithereen", {{"Mary", "10-June"}, {"Jack", "12-Dec"}, {"Joe", "5-Aug"}, {"Daniel", "13-Feb"}});

    add_to_existing(family, "Smithereen", "Joseph", "1-July");

    for (const auto &pair: family)
    {
        std::cout << "Family " << pair.first << ": " << std::ends;

        for (auto &child: pair.second)
            std::cout << child.first <<  " " <<  child.second << " " << std::ends;
        std::cout << std::endl;
    }


    return EXIT_SUCCESS;
}
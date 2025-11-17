#include <iostream>
#include <string>
#include <vector>
#include <map>

void add_member(std::multimap<std::string, std::vector<std::string>> &family,
    const std::string lastname,
    const std::initializer_list<std::string> children)
{
    family.insert(std::make_pair(lastname,std::vector<std::string>(children)));
}

void add_to_existing(std::multimap<std::string, std::vector<std::string>> &family, const std::string &lastname, const std::string &child)
{
    // adds to the first found only!
    auto it = family.find(lastname);
    if (it != family.end())
        it->second.push_back(child);

}

int main()
{
    std::multimap<std::string, std::vector<std::string>> family;

    add_member(family, "Smithereen", {"Mary", "Jack", "Joe", "Daniel"});
    add_member(family, "Smithereen", {"Joe", "Averel", "William"});
    add_member(family, "Thorn", {"Larry", "Jessica", "Madelyn"});

    add_to_existing(family, "Smithereen", "Joseph"); // will be added to the first family only

    for (const auto &pair: family)
    {
        std::cout << "Family " << pair.first << ": " << std::ends;

        for (auto &child: pair.second)
            std::cout << child <<  " " << std::ends;
        std::cout << std::endl;
    }


    return EXIT_SUCCESS;
}
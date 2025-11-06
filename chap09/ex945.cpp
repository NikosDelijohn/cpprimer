#include<iostream>
#include<string>

void official_name(std::string &name, const std::string &prefix, const std::string &suffix)
{
    name.insert(name.cbegin(), prefix.begin(), prefix.end());
    name.append(suffix.begin(), suffix.end());
}

int main()
{
    std::string name = "Broxigar";

    official_name(name, "🪓 ", " The Red");

    std::cout << name << std::endl;

    return EXIT_SUCCESS;
}
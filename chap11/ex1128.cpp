#include <iostream>
#include <map>
#include <vector>
#include <string>

int main()
{
    std::map<std::string, std::vector<int>> map = {{"a",{1,2,3}}, {"b", {4,5,6}}};
    std::map<std::string, std::vector<int>>::iterator find_iter = map.find("b");

    return EXIT_SUCCESS;
}
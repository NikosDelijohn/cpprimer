#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

bool longer_than_five(const std::string & s)
{
    return s.size() >= 5;
}

int main()
{

    std::vector<std::string> svec = {"Sworn", "to", "avenge", "condemn", "to", "Hell", "tempt", "not",
        "the", "blade", "all", "fear", "the", "Sentinel"};

    auto partition_end = std::partition(svec.begin(), svec.end(), longer_than_five);

    for (auto it = svec.begin(); it != partition_end; ++it)
        std::cout << *it << " " << std::ends;
    std::cout << std::endl;

    return EXIT_SUCCESS;
    
}
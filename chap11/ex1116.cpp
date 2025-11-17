#include <iostream>
#include <map>

int main()
{
    std::map<int, int> map = {{1,2}, {3,4}};
    std::map<int, int>::iterator iter = map.begin();

    (*iter).second = 22;

    std::cout << map[1] << std::endl; // expect 22

    return EXIT_SUCCESS;
}
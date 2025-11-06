#include <iostream>
#include <forward_list>

int main()
{
    std::forward_list<int> intlist = {1,2,3,4,5,6,7,8,9,10,11,12,13};

    auto prev = intlist.before_begin();
    auto curr = intlist.begin();

    while(curr != intlist.end())
    {
        if (*curr % 2)
            curr = intlist.erase_after(prev);
        else
            prev = curr++;
    }

    for (auto &elem: intlist)
        std::cout << elem << " " << std::ends;

    std::cout << std::endl;

    return EXIT_SUCCESS;

}
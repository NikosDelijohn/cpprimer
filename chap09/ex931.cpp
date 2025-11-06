#include <iostream>
#include <forward_list>

int main()
{
    std::forward_list<int> ints = {0,1,2,3,4,5,6,7,8};

    auto prev = ints.before_begin();
    auto curr = ints.begin();

    while(curr != ints.end())
    {   

        if (!(*curr % 2))
        {   
            curr = ints.erase_after(prev);
            // previous is not modified! after a deletion 
            // it is still the exact previous element after all.
        }
        else
        {   
            // inserting after
            //curr = ints.insert_after(curr, *curr); // or equivalently (inseting before)
            ints.insert_after(prev, *curr);
            prev = curr++;
        }
        
    }

    for (auto &elem: ints)
        std::cout << elem << " " << std::ends;

    std::cout << std::endl;    

    return EXIT_SUCCESS;
}
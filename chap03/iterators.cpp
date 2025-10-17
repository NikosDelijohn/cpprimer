#include <iostream>
#include <vector>
#include <string>

#include "../help.hpp"

using std::vector;

int main()
{
    vector<int> numbers {1,2,3,4};

    // T is vector<int>::iterator -or- use auto:
    auto start = numbers.begin();
    auto end = numbers.end();

    std::cout << "iterator of type: " << type_name(start) << std::endl;

    std::cout << *start << std::endl;

    for (auto i = start; i != end; ++i)
    {
        std::cout << *i << std::endl;
    }

    std::cout << " ---- " << std::endl; 

    std::cout << *start << std::endl; // 1 
    ++start;
    start+=1;
    std::cout << *start << std::endl; // 3
    start--;
    --start;
    std::cout << *start << std::endl; // 1

    std::cout << *end << std::endl; // undefined, end hasn't been modified and thus it points to one past the last element!
    --end;
    std::cout << *end << std::endl; // fine, expect 4 since it was decremented once!

    // const variant of iterators !
    // T is vector<int>::const_iterator -or- just use auto:
    // const iterators! can only be read and not assign values to the pointee
    auto cstart = numbers.cbegin();
    auto cend = numbers.cend();

    //*cstart = 3; // wrong, assignment on read-only var

    // DEREFERENCES AND MEMBER ACCESS !

    vector<std::string> vec_str {"hi", " everyone!", " this is ", "cpprimer!"};

    auto s = vec_str.begin();
    auto e = vec_str.end();

    *s = "yaw!"; // get a reference to the value!
    //size_t size = *s.size(); // this however, wont work because . operator is higher prio than *. Hence:
    size_t size = (*s).size(); 

    std::cout << " ----- " << std::endl;

    --e;
    std::cout << *e << std::endl;

    // Don't modify the container's size (e.g., push_back) in an iterator controlled loop!
    // DO NOT DO THIS!!!
    for (auto i = s; i != e; ++i)
    {
        std::cout << *e << std::endl; // cpprimer!
        vec_str.push_back("dont!");
        std::cout << *e << std::endl; // ? Undefined ?
        break;
    }
    
    // we can subtract two iterators 

    vector<int> vals {1,2,3,4,5};

    vector<int>::iterator it_a = vals.begin();
    vector<int>::iterator it_mid = it_a + vals.size()/2U;
    
    vector<int>::difference_type diff = it_mid - it_a; // difference is 2 (2 - 0)
    std::cout << diff << std::endl; // expect 2
    diff = vals.end() - it_a;
    std::cout << diff << std::endl;
    
    std::cout << *(it_a + ((vals.end()-vals.begin()) / 2)) <<std::endl;
    return 0;
}
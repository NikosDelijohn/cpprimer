#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

int main()
{
    vector<int> v1; // 0
    vector<int> v2(10); // 10 elements all 0 value-initialized
    vector<int> v3(10,42); // 10 elements all 42
    vector<int> v4{10}; // 1 element; 10
    vector<int> v5{10,42}; // 2 elements; 10 and 42
    vector<string> v6 {10}; // 10 elements all "" value-initialized
    vector<string> v7{10,"hi"}; // 10 elements all "hi"

    vector<int>::iterator start = v1.begin();
    vector<int>::iterator end = v1.end();

    unsigned short elems = 0;
    for (auto i = start; i != end; ++i)
    {
        elems ++;
    }
    std::cout << "v1 has " << elems << " elements" << std::endl;

    start = v2.begin();
    end = v2.end();
    elems = 0 ;

    for (auto i = start; i != end; ++i)
    {
        elems ++;
    }
    std::cout << "v2 has " << elems << " elements" << std::endl;

    // etc... 

    return 0;
}
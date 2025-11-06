#include <iostream>
#include <string>
#include <vector>
using std::vector;
using std::string;

int main()
{

    vector<string> svec;
    svec.reserve(1024);

    string word;
    for (uint i = 0; i != 1000; ++i)
        svec.push_back(std::to_string(i));
    svec.resize(svec.size()+svec.size()/2);

    std::cout << "size: " << svec.size() << " capacity: " << svec.capacity() << std::endl;

    return EXIT_SUCCESS;
}
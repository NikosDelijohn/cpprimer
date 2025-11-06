#include <iostream>
#include <vector>
#include <string>
using std::vector; 
using std::string;

int main()
{
    vector<char> c_vec = {'H','o','w','d','y',' ','p','a','r','t','n','e','r','!'};

    string str(c_vec.begin(), c_vec.end());

    std::cout << str << std::endl;

    // or 
    string str2;
    str2.assign(c_vec.begin(), c_vec.end());

    // or 
    string str3;
    str3.insert(str3.end(), c_vec.begin(), c_vec.end());

    // or
    string str4;
    str4.append(c_vec.begin(), c_vec.end());
    return EXIT_SUCCESS;
}
#include <iostream>
#include <string>
#include <vector>

using std::vector; using std::string;

int main()
{

    vector<int> v1; // 0
    vector<int> v2(10); // 10 elements all 0 value-initialized
    vector<int> v3(10,42); // 10 elements all 42
    vector<int> v4{10}; // 1 element; 10
    vector<int> v5{10,42}; // 2 elements; 10 and 42
    vector<string> v6 {10}; // 10 elements all "" value-initialized
    vector<string> v7{10,"hi"}; // 10 elements all "hi"

    std::cout << v1.size() << " " 
              << v2.size() << " "
              << v3.size() << " "
              << v4.size() << " "
              << v5.size() << " "
              << v6.size() << " "
              << v7.size() << std::endl;

}
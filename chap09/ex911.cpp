#include <iostream>
#include <vector>
using std::vector;

int main()
{
    /*1.*/ vector<int> vec1(10);         // creates a vector of 10 value-initialized integers.
    /*2.*/ vector<int> vec2(10,1);       // creates a vector of 10 integers initialized to 1.
    /*3.*/ vector<int> vec3 = {1,2,3};   // creates a vector of 3 integers, them being 1, 2 and 3.
    /*4.*/ vector<int> vec4{1,2,3};      // equivalent to 3.
    /*5.*/ vector<int> vec5 = vec1;      // copy-initialization. it containes 10 deep copies of vec1.
    /*6.*/ vector<int> vec6(             // range-constructor. contains all but the first element of vec1
                vec1.begin()+1,
                vec1.end()); 
    return EXIT_SUCCESS;
}
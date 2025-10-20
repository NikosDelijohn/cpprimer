#include <iostream>
#include <vector>
#include <string>
#include <typeinfo>
#include "../help.hpp"

using std::vector; using std::string;

int main()
{
    //Vector is a template! Not a type! 
    vector<int> int_values = {1,2,3,4};

    // The type, is vector<int>. 
    decltype(int_values) more_int_values = {5,6,7,8};

    std::cout << type_name(more_int_values) << std::endl;

    // initialization of vectors
    vector <int> ivec; // default empty
    vector<int> ivec2(ivec); // copy elements of ivec into ivec2. 
    vector<int> ivec3 = ivec; // copy elements of ivec into ivec3
    //vector<double> ivec4 = ivec; // wrong, ivec is vector<int> ivec4 is vector<double>

    vector<int> vec5 = {1,2,3}; //ok list initialization
    vector<int> vec6 {1,2,3}; // also ok list initialization 
    //vector<int> vec7(1,2,3,4); // not ok. -but-
    vector<int> vec8(10,-1); // ok, ten int elements each initialized to -1
    vector<string> vec9(10, "hi!"); //ok, ten str elements each initialized to hi!

    vector<string> vec10{10}; // ok , 10 empty strings!

    // range for 
    vector<int> vals {1,2,3,4,5,6,7,8};

    // or use auto
    for (int val: vals)
        std::cout << val << std::endl;

    // or use auto &
    for (int &val: vals)
    {
        val +=1;
        std::cout << val << std::endl;
    }
    
    // also [] returns a REFERENCE to the element at the requested position
    
    std::cout << vals[0] << std::endl; // 2
    int &v = vals[0];
    v += 1;
    std::cout << vals[0] << std::endl; // 3

    // INITIALIZATION OF VECTOR FROM AN ARRAY! 

    int arr[] = {10,20,30,40,50};
    vector<int> vec(std::begin(arr), std::end(arr));

    // This initializes the vector to the same elements the arr has
    for (auto val: vec)
        std::cout << val; // expect 1020304050;
    std::cout << std::endl;

    // or 
    vector<int> vec2(arr+1, arr+3); // copy the values from 20 up to 40 (without 40); Remember, second pointer points to ONE PAST The end
    for (auto val: vec2)
        std::cout << val; // expect 203040;
    std::cout << std::endl; 

    return 0;
}
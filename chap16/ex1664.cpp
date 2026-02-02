#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

template <typename T>
size_t count(const std::vector<T>& vec, const T& sought)
{
    std::cout << "OG call\n";
    return size_t(std::count(vec.begin(), vec.end(), sought));
}

template<>
size_t count(const std::vector<const char*>& vec, const char* const& sought)
{   
    std::cout << "Specialized call\n";
    return size_t(std::count(vec.begin(), vec.end(), sought));

}


int main()
{

    std::vector<int> veci {1,2,3,4,1,5,1,1,1,1,3};
    std::vector<double> vecd {1.0, 1.0, 2.0, 2.0, 3.0, 4.0};
    std::vector<std::string> vecs {"a", "b", "c", "d", "e", "f", "a","a"};
    
    std::cout << count(veci, 1) << std::endl;
    std::cout << count(vecd, 1.0) << std::endl;
    std::cout << count(vecs, std::string("a")) << std::endl;

    std::vector<const char*> vecs2 {"aaa", "aaa", "aaa", "bbb"};
    
    const char* const search_for = "bbb"; 
    std::cout << count(vecs2, search_for) << std::endl;

}
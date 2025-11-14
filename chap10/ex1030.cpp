#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

int main()
{

    std::istream_iterator<int> source(std::cin);
    std::istream_iterator<int> eof;

    std::vector<int> ints(source, eof);    
    std::sort(ints.begin(), ints.end());

    std::ostream_iterator<int> out_iter(std::cout, "\n");
    std::copy(ints.begin(), ints.end(), out_iter);

}
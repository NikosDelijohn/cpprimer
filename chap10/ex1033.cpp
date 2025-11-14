#include <iostream>
#include <iterator>
#include <vector>
#include <fstream>

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << "Usage: " << argv[0] << "input.file output1.file output2.file" << std::endl;
    }    

    std::ifstream source(argv[1]);
    std::ofstream odds(argv[2]);
    std::ofstream evens(argv[3]);

    std::istream_iterator<int> src(source), source_eof;
    std::ostream_iterator<int> odd(odds, " ");
    std::ostream_iterator<int> even(evens, "\n");

    std::vector<int> values(src, source_eof);

    for (auto &elem: values)
        (elem % 2 == 0) ? *even = elem : *odd = elem; // even = elem : odd = elem is equivalent but more preferable this way with deref oper

    return EXIT_SUCCESS;

}
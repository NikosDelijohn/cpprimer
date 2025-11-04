#include "../chap07/ex721.hpp" 
#include <fstream>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << " filename.txt" << std::endl;
        return EXIT_FAILURE;
    }
    
    std::ifstream input_file(argv[1]);
    Sales_data total;
    
    if (read(input_file, total))
    {
        Sales_data trans;
        while(read(input_file, trans))
        {
            if (total.isbn() == trans.isbn())
            {
                total.combine(trans);
            }
            else
            {
                print(std::cout, total) << std::endl;
                total = trans;
            }
        }
        
        print(std::cout, total) << std::endl;
    }
    else
    {
        std::cerr << "No Data!?" << std::endl;
    }

}
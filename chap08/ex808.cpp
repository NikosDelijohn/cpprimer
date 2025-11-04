#include "../chap07/ex721.hpp" 
#include <fstream>

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        std::cerr << "Usage: " << argv[0] << " input-filename.txt output-filename.txt" << std::endl;
        return EXIT_FAILURE;
    }
    
    std::ifstream input_file(argv[1]);
    std::ofstream output_file(argv[2], std::ios::out | std::ios::app);
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
                print(output_file, total) << std::endl;
                total = trans;
            }
        }
        
        print(output_file, total) << std::endl;
    }
    else
    {
        std::cerr << "No Data!?" << std::endl;
    }

}
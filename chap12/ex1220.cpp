#include <fstream>

#include "ex1219/string_blob.hpp"
#include "ex1219/string_blob_ptr.hpp"

// compile with g++ ex1220.cpp ex1219/string_blob.cpp ex1219/string_blob_ptr.cpp

int main()
{

    std::ifstream src("ex1220-input.txt");

    String_Blob blob;

    std::string word;
    while (src >> word)
    {   
        blob.push_back(word);
    }

    auto beg = std::begin(blob);
    
    while(true)
    {
        try
        {   
        
            std::cout << beg.dereference() << std::endl;
            beg.increment();
        }
        catch (std::out_of_range e)
        {
            std::cout << "We have reached the end. Adios!" << std::endl;
            break;
        }
    }
        
    return EXIT_SUCCESS;
}
#include "string_blob_ptr.hpp"
#include "string_blob.hpp"

void print_blob(String_Blob &blob)
{
    for(auto beg = std::begin(blob); beg != std::end(blob); beg.increment())
    {   
        std::cout << beg.dereference() << " ";
    }
    std::cout << std::endl;
}

int main()
{

    String_Blob blob_a({"This", "is", "it!"});
    String_Blob_Ptr ptr = std::begin(blob_a);

    std::cout << ptr.dereference() << std::endl; // This
    std::cout << (++ptr).dereference() << std::endl; // is

    std::string curr = (ptr++).dereference(); 
    
    std::cout << curr << std::endl; // is 
    std::cout << ptr.dereference() << std::endl; // it!

    curr = (--ptr).dereference(); 
    std::cout << curr << std::endl; // is
    curr = (ptr--).dereference(); 
    std::cout << curr << std::endl; // is

    return EXIT_SUCCESS;
}
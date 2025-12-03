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
    String_Blob blob_b(blob_a);

    std::cout << blob_a.get_uses() << " vs " << blob_b.get_uses() << std::endl;

    std::cout << blob_a[0] << " ";

    auto blobptr = std::begin(blob_a);
    
    std::cout << blobptr[1] << " Sparta!\n";

    
    return EXIT_SUCCESS;
}
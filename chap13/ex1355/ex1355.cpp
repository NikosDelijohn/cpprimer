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

    String_Blob blob_c = String_Blob({"Ha"}).push_back("Hoe").push_back("Yeeeeet!");
    print_blob(blob_c);
    
    return EXIT_SUCCESS;
}
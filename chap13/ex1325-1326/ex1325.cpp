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

    blob_a.push_back("Or is it?");

    print_blob(blob_a);
    print_blob(blob_b);

    String_Blob blob_c = String_Blob();
    blob_c = blob_b;
    blob_c.pop_back();

    print_blob(blob_c); // won't affect blob_b due to copy-assignment oper.
    print_blob(blob_b);
    
    return EXIT_SUCCESS;
}
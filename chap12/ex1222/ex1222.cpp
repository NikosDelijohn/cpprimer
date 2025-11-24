#include "string_blob.hpp"
#include "string_blob_ptr.hpp"
#include "const_string_blob_ptr.hpp"

int main()
{
    String_Blob blob = {"This", "is", "blob"};

    Const_String_Blob_Ptr cptr(blob);  
    String_Blob_Ptr ptr(blob);
    
    //cptr.dereference() = "Hey!"; // no can do!
    std::cout << cptr.dereference() << std::endl;
    cptr.increment();
    std::cout << cptr.dereference() << std::endl;
    cptr.increment();
    std::cout << cptr.dereference() << std::endl;

    // ---
    ptr.dereference() = "It";
    std::cout << ptr.dereference() << std::endl;
    ptr.increment();
    std::cout << ptr.dereference() << std::endl;
    ptr.increment();
    std::cout << ptr.dereference() << std::endl;

    return EXIT_SUCCESS;
}

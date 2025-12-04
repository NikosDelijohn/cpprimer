#include <iostream>
#include <string>

#include "string_blob.hpp"
#include "string_blob_ptr.hpp"


struct ptr_to_ptr
{
    String_Blob_Ptr* ptr;
    inline String_Blob_Ptr& operator->() const noexcept
    {
        return *ptr;
    }
};

int main()
{
    String_Blob blob({"Hello", "From", "The", "Other", "Side"});
    String_Blob_Ptr blob_ptr = std::begin(blob);
    ptr_to_ptr blob_ptr2 {&blob_ptr};

    std::cout << blob[0] << "==" << *blob_ptr << "==" << *(blob_ptr2.operator->()) << std::endl;
        /*
        1. operator-> returns a class-type (String_Blob_Ptr&), NOT a raw pointer.
        2. HOWEVER: drill-down into that class type ONLY happens if a MEMBER is requested (i.e., ptr->member).
        3. Since no member access follows (we call operator->() explicitly), NO implicit call to String_Blob_Ptr::operator->() occurs.
        4. We explicitly call blob_ptr2.operator->(), which returns a reference to blob_ptr (class type).
        5. We dereference that class object:  *(blob_ptr)
        6. This triggers String_Blob_Ptr::operator*(), which returns a std::string&.
        7. operator<< on std::ostream consumes the string reference and prints the whole word "Hello".
        */
    return EXIT_SUCCESS;
}
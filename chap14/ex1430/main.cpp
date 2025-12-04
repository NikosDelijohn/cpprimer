#include "string_blob.hpp"
#include "string_blob_ptr.hpp"
#include <iostream>
#include <cctype>

int main() {
    String_Blob blob({"Hello", "world", "C++!"});
    
    // Get an iterator
    String_Blob_Ptr it = std::begin(blob);

    // Example: print the length of each string using -> syntax
    for (; it != std::end(blob); ++it) {
        std::cout << "Length: " << it->size() << "\n";
    }

    std::cout << std::endl;

    // Example: convert first character of each string to uppercase
    for (it = std::begin(blob); it != std::end(blob); ++it) {
        it->at(0) = std::toupper(it->at(0));
    }

    // Print updated blob
    for (it = std::begin(blob); it != std::end(blob); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}

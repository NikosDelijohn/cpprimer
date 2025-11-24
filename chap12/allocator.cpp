#include <memory>
#include <string>
#include <vector>
#include <iostream>

int main()
{
    /*
    Allocators enable us to differentiate between:
        A) Allocation and construction of heap elements
        B) Destruction and de-allocation of heap elements

    They allow us to perform these actions separately, and not allocate and construct
    or inversely, delete and free like `new` and `delete` does respectively.

    included in then <memory> header and use like this:
    */

    constexpr int num_elements = 5;
    std::allocator<std::string> alloc;

    // A) 1. Allocate space for n strings
    std::string *const ptr = alloc.allocate(num_elements); // returns a poitner to the first element's allocated space

    auto q = ptr; // Reminder: top-level const is dropped by auto!

    // A) 2. Construct strings
    alloc.construct(q++); // construct an empty string and increment the pointer
    alloc.construct(q++, 10, 'A'); // construct the string "AAAAAAAAAA" and increment the pointer
    alloc.construct(q++, "hello there!"); //construct the string "hello there!" and increment the pointer
    
    // last 2 slots are raw unconstructed memory
    // Note that q now points to unconstructed memory (due to post-increment on line 27)
    // dereferencing q i.e., unconstructed memory ptr, is a serious error. -> UB

    // B) 1. Destroy strings
    while(q != ptr)
        alloc.destroy(--q); // note that pre-decrement is required. q was pointing to raw unconstructed memory
    
    // B) 2. De-allocate the memory
    alloc.deallocate(ptr, num_elements);

    // --- allocator Algorithms ---

    std::string *const ptr2 = alloc.allocate(4);
    std::vector<std::string> vec = {"A", "B", "C", "D"};

    // Copy 
    auto end = std::uninitialized_copy(vec.begin(), vec.end(), ptr2);
    
    auto beg = ptr2;
    while(beg != end)
        std::cout << *beg++ << std::endl;

    while(beg != ptr2)
        alloc.destroy(--beg);
    
    // Fill assumes that the unconstructed raw memory is large enough to hold vec.size() elements
    end = std::uninitialized_fill_n(ptr2, vec.size(), "Hello!");

    while(beg != end)
        std::cout << *beg++ << std::endl;

    while(beg != ptr2)
        alloc.destroy(--beg);

    return EXIT_SUCCESS;
}
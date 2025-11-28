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
    std::string *const ptr = alloc.allocate(num_elements); // returns a pointer to the first element's allocated space

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

    constexpr int num_elements2 = 4;
    std::string *const ptr2 = alloc.allocate(num_elements2);
    std::vector<std::string> vec = {"A", "B", "C", "D"};

    // Copy that does not require an initialized range
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

    alloc.deallocate(ptr2, num_elements2);

    // =====================================================================
    // IMPORTANT NOTE ABOUT RAW UNINITIALIZED MEMORY AND BUILT-IN TYPES
    // =====================================================================
    //
    // For *built-in types* (like int, double, char), the C++ object model
    // says:
    //
    //   - They have *trivial constructors and destructors*
    //   - Writing a value into raw uninitialized memory *starts the object
    //     lifetime automatically*
    //
    // Therefore:
    //
    //   - You do NOT need alloc.construct() for built-in types
    //   - You do NOT need alloc.destroy() for built-in types
    //   - You can treat raw allocated memory as storage for the object
    //     simply by assigning to it
    //
    // Example:
    //
    //      int* p = alloc_int.allocate(5);
    //      p[0] = 42;   // This *creates* the int object in that storage
    //
    // For *non-trivial types* (like std::string), you MUST use construct()
    // because the object has a real constructor and internal invariants.
    //
    // =====================================================================

    std::allocator<int> alloc_int;
    auto pi = alloc_int.allocate(5);   // allocate space for 5 ints


    *(pi+0) = 1;
    *(pi+1) = 2;
    *(pi+2) = 3;
    *(pi+3) = 4;
    *(pi+4) = 5;

    for(size_t idx=0; idx < 5; ++idx)
        std::cout << pi[idx] << std::endl;

    alloc_int.deallocate(pi, 5);

    return EXIT_SUCCESS;
}
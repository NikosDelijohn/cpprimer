#include <iostream>
#include <memory>
#include <string>

int main()
{
    std::allocator<std::string> alloc;

    size_t capacity = 1;
    size_t size = 0;

    std::string* base = alloc.allocate(capacity);

    std::string word;
    while (std::cin >> word)
    {
        // If full, grow:
        if (size == capacity) {
            size_t new_cap = capacity * 2;
            std::string* new_base = alloc.allocate(new_cap);

            // Move old objects into new space
            for (size_t i = 0; i < size; ++i) {
                alloc.construct(new_base + i, std::move(base[i]));
                alloc.destroy(base + i);
            }

            alloc.deallocate(base, capacity);

            base = new_base;
            capacity = new_cap;
        }

        // Construct new element
        alloc.construct(base + size, word);
        ++size;
    }

    std::cout << "Total elements: " << size << std::endl;

    // Destroy everything
    for (size_t i = 0; i < size; ++i)
        alloc.destroy(base + i);

    alloc.deallocate(base, capacity);
}

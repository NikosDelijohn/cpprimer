#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

int main() {
    const char a1[] = "hello";
    const char a2[] = "hello";

    std::vector<const char*> v1 = { a1 };
    std::vector<const char*> v2 = { a2 };

    // Vector holds const char pointers. These pointers will be
    // checked for equality == rather than the characters they
    // point to. So we are actually comparing addresses here.
    bool result = std::equal(v1.begin(), v1.end(), v2.begin());

    std::cout << "Pointer comparison result: " << result << "\n";

    // Show actual string comparison
    std::cout << "strcmp result: " << (std::strcmp(a1, a2) == 0) << "\n";
}
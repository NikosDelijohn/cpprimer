#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

struct NonCopyableNonMovable {
    NonCopyableNonMovable() = default;
    NonCopyableNonMovable(const NonCopyableNonMovable&) = delete;
    NonCopyableNonMovable(NonCopyableNonMovable&&) = delete;

    bool operator<(const NonCopyableNonMovable&) const { return false; }
};

// ELEMENTS STORED MUST BE COPY CONSTRUCTIBLE OR MOVE CONSTRUCTIBLE

int main()
{

    std::set<NonCopyableNonMovable> set;
    NonCopyableNonMovable a;

    set.insert(a); // error, use of deleted function!

    return 0;
}
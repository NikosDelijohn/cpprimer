#include <iostream>
#include <string>
using namespace std;

class Point {
public:
    int x;

    Point(int v = 0) : x(v) {
        cout << "[ctor] Point(" << v << ")\n";
    }

    Point(const Point& other) : x(other.x) {
        cout << "[copy ctor] Point copied" << " (x=" << other.x << ")\n";
    }

    Point& operator=(const Point& other) {
        cout << "[copy assignment] Point assigned" << " (x=" << other.x << ")\n";
        x = other.x;
        return *this;
    }
};

Point global(5);

Point foo_bar(Point arg)  // *** copy ctor called when passing argument ***
{
    // 1. Copy constructor: function parameter 'arg' is initialized from caller's argument

    Point local = arg;  // *** copy ctor ***

    Point* heap = new Point(global);
    // 2. Copy constructor: direct-initializing heap object from 'global'

    *heap = local;
    // 3. Copy assignment operator (NOT copy ctor)

    Point pa[4] = { local, *heap };
    // 4. Copy ctor for pa[0] from local
    // 5. Copy ctor for pa[1] from *heap
    // pa[2] and pa[3] use default ctor

    return *heap;
    // 6. Copy ctor: returning by value constructs a copy from *heap
}

int main() {
    cout << "Calling foo_bar(global)...\n";
    Point result = foo_bar(global);
    // 7. Copy ctor: result is initialized from return value

    return 0;
}

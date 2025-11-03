#include <iostream>

class Rectangle {
    int width;
    int height;

public:
    // Main constructor
    Rectangle(int w, int h) : width(w), height(h) {
        std::cout << "Rectangle(" << width << ", " << height << ") constructed\n";
    }

    // Delegating constructor: square
    Rectangle(int size) : Rectangle(size, size) {  // calls the main constructor
        std::cout << "Delegating constructor called for square\n";
    }

    void print() const {
        std::cout << "Width: " << width << ", Height: " << height << "\n";
    }
};

int main() {
    Rectangle r1(3, 5);  // calls main constructor directly
    r1.print();

    Rectangle r2(4);     // calls delegating constructor
    r2.print();

    return 0;
}
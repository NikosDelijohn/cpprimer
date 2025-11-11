#include <iostream>
#include <vector>

int main() {
    int x = 10;
    int y = 20;

    // 1. No capture
    auto f1 = []() { return 42; };
    std::cout << f1() << "\n";

    // 2. Capture by value
    auto f2 = [x]() { /*x = x+2; NOT allowed*/ return x + 1; };
    std::cout << f2() << "\n";  // uses copy of x

    // 3. Capture by reference
    auto f3 = [&x]() { x += 5; };
    f3();
    std::cout << x << "\n";  // x modified

    // 4. Mixed capture
    auto f4 = [x, &y]() { return x + (++y); };
    std::cout << f4() << "\n";

    // 5. Default capture implicitly by value (infer the variables that are required to be captured)
    auto f5 = [=]() { return x + y; };
    std::cout << f5() << "\n";

    // 6. Default capture implicitly by reference (infer the variables that are required to be captured)
    auto f6 = [&]() { x++; y++; };
    f6();
    std::cout << x << " " << y << "\n";

    // 7. Mutable lambda (modifies its own captured-by-value state)
    auto f7 = [x]() mutable {
        x++;            // allowed only with mutable
        return x;
    };
    std::cout << f7() << " " << f7() << "\n";  // internal x increments

    // 8. Lambda with explicit return type
    auto f8 = [](double a, double b) -> double { return a / b; };
    std::cout << f8(10, 2) << "\n";

    // 9. Lambda
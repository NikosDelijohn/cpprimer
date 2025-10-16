#include <iostream>

using std::cin;

int main()
{

    int a, b;
    cin >> a >> b; //fine 
    //cout << a << b; //not fine! cout must be fully qualified to std::cout manually
    std::cout <<a << b << std::endl;
    using std::cout;
    cout << a << b << std::endl;
    
    return 0;
}
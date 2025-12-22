#include <iostream>
#include <memory>

class DebugDelete
{
public:
    DebugDelete() = default;
    template <class Object>
    void operator()(Object *obj) const
    {
        std::cout << "Deleting smart_ptr\n";
        delete obj;
    }
};

int main()
{   
    std::unique_ptr<int, DebugDelete> ip(new int(42), DebugDelete());    
    std::cout << *ip << std::endl;

    return EXIT_SUCCESS;
}
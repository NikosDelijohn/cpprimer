#include "text_query.hpp"
#include "query_result.hpp"

int main()
{
    std::ifstream file("input.txt");
    Text_Query tq(file);

    std::cout << R"(  _  _     ___   ___)" << std::endl;
    std::cout << R"( | \| |___/ _ \ / _ \)" << std::endl;
    std::cout << R"( | .` (_-< (_) | (_) |)" << std::endl;
    std::cout << R"( |_|\_/__/\___/ \__\_\)" << std::endl;
    std::cout << " Not So Optimized Querying\n"
              << " v1. Type 'q' to Exit\n"
              << " ?> ";
    
    std::string word;
    while (std::cin >> word && (word != "q"))
    {
        auto qr = tq.query(word);
        print(std::cout, qr) << "\n ?> ";
    }

    std::cout << "Thank you for using NsOQ. Adios!👋👋" << std::endl;
    return EXIT_SUCCESS;
}
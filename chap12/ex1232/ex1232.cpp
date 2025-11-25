#include "text_query.hpp"
#include "query_result.hpp"

//g++ ex1232.cpp string_blob.cpp text_query.cpp string_blob_ptr.cpp

int main()
{
    std::ifstream file("ex1232-input.txt");
    Text_Query tq(file);

    std::cout << R"(  ___  ___   ___  )" << std::endl;
    std::cout << R"( / __|/ _ \ / _ \)" << std::endl;
    std::cout << R"( \__ \ (_) | (_) |)" << std::endl;
    std::cout << R"( |___/\___/ \__\_\)" << std::endl;
    std::cout << " Somewhat Obfuscated Querying\n"
              << " v2. Type 'q' to Exit\n"
              << " ?> ";
    
    std::string word;
    while (std::cin >> word && (word != "q"))
    {
        auto qr = tq.query(word);
        print(std::cout, qr) << "\n ?> ";
    }

    std::cout << "Thank you for using SOQ. Adios!👋👋" << std::endl;
    return EXIT_SUCCESS;
}
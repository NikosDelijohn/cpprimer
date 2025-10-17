#include <iostream>
#include <string>
#include <cctype>
#include <vector>

using std::string; using std::vector;

int main()
{
    vector<string> input_lines;
    std::string input_line;
    string input{};
    unsigned short words = 0;

    while (std::cin >> input)
    {
        ++words;

        for (char &c: input)
            c = std::toupper(c);

        input_line += (input + ", ");

        if (words == 8)
        {
            input_lines.push_back(input_line);
            input_line = "";
            words = 0;
        }
    }

    input_lines.push_back(input_line);

    for (auto line: input_lines)
        std::cout << line << std::endl;

    return 0;
}
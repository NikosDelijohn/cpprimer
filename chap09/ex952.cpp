#include <iostream>
#include <stack>
#include <string>
#include <fstream>

int main()
{
    std::ifstream source("ex952-input.txt");
    std::string word;
    std::stack<std::string> stack;

    bool paren_seen = false;

    while(source >> word)
    {
        stack.push(word);

        if (word == "(")
            paren_seen = true;
        
        if (word == ")" && paren_seen)
        {
            paren_seen = false;
            
            while(stack.top() != "(")
                stack.pop();
            stack.pop(); // remove also the (
            stack.push("<replaced>");
        }
    }

    while(!stack.empty())
    {
        std::cout << stack.top() << std::endl;
        stack.pop();
    }   

    return EXIT_SUCCESS;
}
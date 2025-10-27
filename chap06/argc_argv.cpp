#include <iostream>
#include <cctype>

void capitalize(char* str)
{   

    for (size_t idx = 0u; idx < sizeof(str); ++idx)
        str[idx] = std::toupper(str[idx]); 
}

int main(int argc, char **argv /* or char *argv[]*/)
{
    /*
        argv points to char* like "cliarg1", "cliarg2" etc.
        No CONST here, hence these arguments can be freely 
        modified! 
    */

    std::cout << "Progname: " << *argv << std::endl;
    capitalize(*argv);
    std::cout << "Progname: " << *argv << std::endl;

}
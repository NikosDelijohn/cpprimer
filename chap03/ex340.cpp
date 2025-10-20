#include <cstring>
#include <iostream>

int main()
{
    const char arrA[256] = "String One!";
    const char arrB[256] = "String Two!";

    char arrC[256*2 + 1]; // + 1 for worst case having size for NULL '\0'

    strcpy(arrC, arrA);
    strcat(arrC, arrB);

    std::cout << arrC << std::endl;

    return 0;

}
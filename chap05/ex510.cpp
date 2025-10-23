#include <iostream>

int main()
{
    unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
    char ch;

    while (std::cin >> ch)
    {
        switch (ch)
        {
            case 'A':
            case 'a': ++aCnt; break;
            case 'E': 
            case 'e': ++eCnt; break;
            case 'I':
            case 'i': ++iCnt; break;
            case 'O':
            case 'o': ++oCnt; break;
            case 'U':
            case 'u': ++uCnt; break;
        }
    }

    std::cout << "Number of vowel a: \t" << aCnt << std::endl
              << "Number of vowel e: \t" << eCnt << std::endl
              << "Number of vowel i: \t" << iCnt << std::endl
              << "Number of vowel o: \t" << oCnt << std::endl
              << "Number of vowel u: \t" << uCnt << std::endl;

    return 0;
}

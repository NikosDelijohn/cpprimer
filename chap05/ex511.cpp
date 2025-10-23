#include <iostream>
#include <string>

int main()
{
    unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
    unsigned blankCnt = 0, tabCnt = 0, nlCnt = 0;
    std::string line;
    while (std::getline(std::cin, line))
    {
        for (char ch: line)
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
                case ' ': ++blankCnt; break;
                case '\t': ++tabCnt; break;
            }
        
        ++nlCnt; // std::getline doesn't account for new lines
    }

    std::cout << "Number of vowel a: \t" << aCnt << std::endl
              << "Number of vowel e: \t" << eCnt << std::endl
              << "Number of vowel i: \t" << iCnt << std::endl
              << "Number of vowel o: \t" << oCnt << std::endl
              << "Number of vowel u: \t" << uCnt << std::endl
              << "Number of tabs   : \t" << tabCnt << std::endl
              << "Number of newline: \t" << nlCnt << std::endl
              << "Number of blanks : \t" << blankCnt << std::endl;

    return 0;
}

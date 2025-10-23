#include <iostream>
#include <string>

int main()
{
    unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
    unsigned blankCnt = 0, tabCnt = 0, nlCnt = 0;
    unsigned ffCnt = 0, flCnt = 0, fiCnt = 0;
    std::string line;

    bool f_seen = false;
    while (std::getline(std::cin, line))
    {
        for (char ch: line)
            switch (ch)
            {
                case 'A':
                case 'a': ++aCnt; f_seen = false; break;
                case 'E': 
                case 'e': ++eCnt; f_seen = false; break;
                case 'I':
                case 'i': 
                    {
                        ++iCnt;
                        if (f_seen)
                            ++fiCnt;
                        f_seen = false;
                        break;
                    }
                case 'O':
                case 'o': ++oCnt;f_seen = false;  break;
                case 'U':
                case 'u': ++uCnt; f_seen = false; break;
                case ' ': ++blankCnt; f_seen = false; break;
                case '\t': ++tabCnt; f_seen = false; break;
                case 'f': 
                    {
                        if (f_seen)
                            ++ffCnt; 
                        
                        f_seen = true;
                        break;
                    }
                case 'l':
                    {
                        if (f_seen)
                            ++flCnt;
                        f_seen = false;
                        break;
                    }
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
              << "Number of blanks : \t" << blankCnt << std::endl
              << "Number of ff     : \t" << ffCnt << std::endl
              << "Number of fl     : \t" << flCnt << std::endl
              << "Number of fi     : \t" << fiCnt << std::endl;

    return 0;
}

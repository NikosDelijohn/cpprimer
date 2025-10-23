#include <iostream>
#include <string>

int main()
{

    const char *grades[] = {"F", "D", "C", "B", "A", "A++"};
    ptrdiff_t size = std::end(grades) - std::begin(grades);

    int score;
    std::cin >> score;

    std::string result;

    if (score == 100)
    {
        result = grades[size-1];
    }
    else if (score < 60)
    {
        result = grades[0];
    }
    else
    {
        result = const_cast<char *>(grades[(score-50)/10]);

        if (score % 10 > 7)
            result += '+';
        else if (score % 10 < 4)
            result += '-';

    }
    
    std::cout << "Grade: " << result << std::endl;
    
}
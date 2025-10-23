#include <iostream>
#include <string>

int main()
{

    const char *grades[] = {"F", "D", "C", "B", "A", "A++"};
    ptrdiff_t size = std::end(grades) - std::begin(grades);

    int score;
    std::cin >> score;

    std::string result =
        (score == 100) ? std::string(grades[size-1]) :
        (score < 60) ? std::string(grades[0]) :
        std::string(grades[(score-50)/10]) +
            ((score % 10 > 7) ? "+" : ((score % 10 < 4) ? "-" : ""));

                         
    std::cout << "Grade: " << result << std::endl;
    
}
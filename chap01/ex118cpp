#include <iostream>

int main()
{
    int old_number, new_number;
    int current_cc;

    if (std::cin >> old_number)
    {
        current_cc = 1;

        while (std::cin >> new_number)
        {
            if (old_number == new_number)
            {
                current_cc += 1;
            } 
            else
            {
                std::cout << "Number " << old_number << " appeared " << current_cc << " times." << std::endl;
                current_cc = 1;
                old_number = new_number;
            }
        }
        std::cout << "Number " << old_number << " appeared " << current_cc << " times." << std::endl;
    }

    return 0;
}
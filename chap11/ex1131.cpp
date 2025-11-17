#include <iostream>
#include <map>

int main()
{
    std::multimap<std::string, std::string> works =
    {
        {"Alice Morton", "Sky Without Stars"},
        {"James Harper", "The Broken Circle"},
        {"Alice Morton", "Whispers of the North"},
        {"Elena Rivers", "Midnight Lanterns"},
        {"James Harper", "A Storm of Echoes"},
        {"Tom Gallagher", "Harbor of Lost Voices"},
        {"Elena Rivers", "The Wind Between Worlds"},
        {"Alice Morton", "The Far Shore"},
        {"James Harper", "Portrait of a Ghost"},
        {"Tom Gallagher", "The Red Field"}
    };

    std::string to_remove = "Alice Morton";
    auto find_iter = works.find(to_remove);

    if (find_iter == works.end())
    {
        std::cout << "No such author!" << std::endl;
        return EXIT_FAILURE;
    }

    works.erase(find_iter);

    for (const auto &pair: works) // Sky without stars is missing
        std::cout << pair.first << " " << pair.second << std::endl;


    return EXIT_SUCCESS;
}
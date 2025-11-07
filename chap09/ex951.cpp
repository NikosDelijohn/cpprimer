#include <iostream>
#include <string>

class date
{
public:

    date(const std::string&);
    date() = default;
    inline std::string get_date() const
    {
        return std::to_string(day) + " - " 
             + std::to_string(month) + " - " 
             + std::to_string(year);
    }
    inline unsigned month_to_int(const std::string &month_str) const
    {
        if      (month_str.find("Jan") != std::string::npos) return 1;
        else if (month_str.find("Feb") != std::string::npos) return 2;
        else if (month_str.find("Mar") != std::string::npos) return 3;
        else if (month_str.find("Apr") != std::string::npos) return 4;
        else if (month_str.find("May") != std::string::npos) return 5;
        else if (month_str.find("Jun") != std::string::npos) return 6;
        else if (month_str.find("Jul") != std::string::npos) return 7;
        else if (month_str.find("Aug") != std::string::npos) return 8;
        else if (month_str.find("Sep") != std::string::npos) return 9;
        else if (month_str.find("Oct") != std::string::npos) return 10;
        else if (month_str.find("Nov") != std::string::npos) return 11;
        else if (month_str.find("Dec") != std::string::npos) return 12;
        else
            return 0;
    }
    
private:

    unsigned day;
    unsigned month;
    unsigned year;

};

date::date(const std::string &init)
{
    // Month day, year
    // dd/mm/yyyy   
    // Mon day, year

    if (init.find("/") != std::string::npos)
    {
        auto first_slash = init.find_first_of("/");
        auto second_slash = init.find_first_of("/", first_slash + 1);

        day = std::stoi(init.substr(0, first_slash));
        month = std::stoi(init.substr(first_slash+1,second_slash));
        year = std::stoi(init.substr(second_slash+1,init.size()));
    }
    else
    {
        auto iter = init.cbegin();
        
        // Consume Month
        while (std::isalpha(*iter))
            ++iter;
        
        std::string::difference_type end_pos = iter - init.cbegin();
        
        month = month_to_int(init.substr(0, end_pos));
        
        auto day_part_start = init.find_first_of("0123456789");
        auto day_part_end   = init.find(",");
        day = std::stoi(init.substr(day_part_start, day_part_end-day_part_start));

        auto year_part_start = init.find_first_of("0123456789", day_part_end);
        year = std::stoi(init.substr(year_part_start, init.size() - year_part_start));
    }   
}

int main()
{
    
    date first_format("02/11/1996");
    std::cout << first_format.get_date() << std::endl; 
    date second_format("Nov 2, 1996");
    std::cout << second_format.get_date() << std::endl;
    date third_format("November 2, 1996");
    std::cout << third_format.get_date() << std::endl;

    return EXIT_SUCCESS;
}
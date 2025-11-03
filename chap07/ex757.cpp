#include <iostream>
#include <string>

class Account
{
public:
    static double get_rate();
    static void update_rate(const double &);
    Account(std::string);
private:
    std::string account_owner;
    double amount;
    static double interest_rate;
    static double init_rate();
};

Account::Account(std::string name):
    account_owner(name),
    amount(0)
{}

double Account::init_rate() { return 1.0; }
double Account::interest_rate = init_rate();
double Account::get_rate() {return interest_rate;}
void Account::update_rate(const double &new_rate) {interest_rate = new_rate;}

int main()
{
    Account new_acc("Paul");    
    std::cout << new_acc.get_rate() << " ";

    return EXIT_SUCCESS;
}
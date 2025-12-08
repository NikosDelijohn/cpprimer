#include <iostream>
#include <string>

class Quote
{
public:

    Quote() = default;
    Quote(const std::string &book, const double sales_price): 
        isbn(book), price(sales_price){}

    virtual ~Quote() = default;
    virtual double net_price(size_t n) const {return n * price;}

    std::string get_isbn() const { return isbn; }

private:
    std::string isbn;

protected:
    double price = 0.0;
};

class Limited_Quote: public Quote
{
public:
    Limited_Quote() = delete;
    Limited_Quote(const std::string &book, const double sales_price, const size_t max_qty, const double discount):
        Quote(book, sales_price), max_quantity(max_qty), discount(discount)
    {}

    virtual ~Limited_Quote() = default;
    virtual double net_price(size_t n) const override
    {
        if (n < max_quantity )
            return (n * price) * (1.0 - discount);
        else 
            return n * price;
    }

private:
    size_t max_quantity;
    double discount;
};

std::ostream& print_total(std::ostream &out, const Quote& quote, size_t copies)
{
    out << "Book with ISBN: " << quote.get_isbn() << " sold #" << copies << " copies."
        << " Total due: " << quote.net_price(copies) << std::endl;

    return out;
}

int main()
{

    Limited_Quote bq("1111-2222-3333", 12.0, 4, .30);

    print_total(std::cout, bq, 3); // 25.2
    print_total(std::cout, bq, 5); // 60, no discount!

    return EXIT_SUCCESS;    
}
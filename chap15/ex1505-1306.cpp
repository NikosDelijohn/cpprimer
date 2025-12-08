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

class Bulk_Quote: public Quote
{
public:
    Bulk_Quote() = delete;
    Bulk_Quote(const std::string &book, const double sales_price, const size_t min_qty, const double discount):
        Quote(book, sales_price), min_quantity(min_qty), discount(discount)
    {}

    virtual ~Bulk_Quote() = default;
    virtual double net_price(size_t n) const override
    {
        if (n >= min_quantity)
            return (n * price) * (1.0 - discount);
        else 
            return n * price;
    }

private:
    size_t min_quantity;
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

    Bulk_Quote bq("1111-2222-3333", 12.0, 4, .30);

    print_total(std::cout, bq, 4); // 33.6 
    print_total(std::cout, bq, 2); // 24.0 no discount applied here.

    return EXIT_SUCCESS;
}
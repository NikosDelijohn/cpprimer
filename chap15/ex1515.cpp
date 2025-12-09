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

class Discount_Quote: public Quote
{
public:
    Discount_Quote() = default;
    Discount_Quote(const std::string &dbook, const double &dsales_price,
                   const double &ddiscount, const size_t &dnum_of_copies):
        Quote(dbook, dsales_price), discount(ddiscount), quantity(dnum_of_copies){}
    virtual ~Discount_Quote() = default;
    
    virtual double net_price(size_t) const = 0;
    
protected:
    double discount = 0.0;
    size_t quantity = 0;
};

class Bulk_Item: public Discount_Quote 
{
    // apply discount if quantity >= N
public:
    Bulk_Item() = default;
    Bulk_Item(const std::string &bbook, const double &bsales_price, const size_t &bmax_qty, const double &bdiscount):
        Discount_Quote(bbook, bsales_price, bdiscount, bmax_qty)
    {}

    virtual ~Bulk_Item() = default;
    virtual double net_price(size_t n) const override
    {
        if (n >= quantity)
            return (n * price) * (1.0 - discount);
        else 
            return Quote::net_price(n);
    }
};

std::ostream& print_total(std::ostream &out, const Quote& quote, size_t copies)
{
    out << "Book with ISBN: " << quote.get_isbn() << " sold #" << copies << " copies."
        << " Total due: " << quote.net_price(copies) << std::endl;

    return out;
}

int main()
{

    Bulk_Item bq("1111-2222-3333", 1.0, 100, .50);

    print_total(std::cout, bq, 100); // 50 
    print_total(std::cout, bq, 80); // 80
    
    return EXIT_SUCCESS;    
}
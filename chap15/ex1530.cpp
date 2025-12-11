#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <set>

#define NDEBUG

class Quote
{
public:

    Quote() = default;
    Quote(const std::string &book, const double sales_price): 
        isbn(book), price(sales_price)
    {
#ifndef NDEBUG
        std::cout << "(BASE) [Quote(const string&, const double)]: Constructor called.\n";
#endif
    }

    Quote(const Quote& other):
        isbn(other.isbn), price(other.price)
    {
#ifndef NDEBUG
        std::cout << "(BASE) [Quote(const Quote&)]: Copy Constructor called.\n";
#endif
    }
    
    Quote(Quote&& other) noexcept:
        isbn(std::move(other.isbn)), price(other.price)
    {
#ifndef NDEBUG
        std::cout << "(BASE) [Quote(Quote&&)]: Move Constructor called.\n";
#endif
    } 
    
    Quote& operator=(const Quote& rhs)
    {
#ifndef NDEBUG
        std::cout << "(BASE) [Quote::operator=(const Quote&)]: Copy Assignment called.\n";
#endif
        if (this != &rhs)
        {
            isbn = rhs.isbn;
            price = rhs.price;
        }
        return *this;
    }

    Quote& operator=(Quote&& rhs) noexcept
    {
#ifndef NDEBUG
        std::cout << "(BASE) [Quote::operator=(Quote&&)]: Move Assignment called.\n";
#endif
        if (this != &rhs)
        {
            isbn = std::move(rhs.isbn);
            price = rhs.price;

            // string will destroy gracefully itself (manages its own memory)
            // price is trivially destructible (double) 
            // nothing more to do here.
        }
        return *this;
    }

    virtual ~Quote() = default;
    virtual double net_price(size_t n) const {return n * price;}

    virtual Quote* clone() const & {return new Quote(*this);}
    virtual Quote* clone() && { return new Quote(std::move(*this)); }

    std::string get_isbn() const { return isbn; }

private:
    std::string isbn;

protected:
    double price = 0.0;

    friend bool operator==(const Quote &lhs, const Quote &rhs)
    {
        return lhs.isbn == rhs.isbn && lhs.price == rhs.price; 
    }
};

class Discount_Quote: public Quote
{
public:
    Discount_Quote() = default;
    Discount_Quote(const std::string &dbook, const double &dsales_price,
                   const double &ddiscount, const size_t &dnum_of_copies):
        Quote(dbook, dsales_price), discount(ddiscount), quantity(dnum_of_copies)
    {
#ifndef NDEBUG
        std::cout << "(ABSTRACT BASE) [Discount_Quote(const string&, const double, const size_t &, const double &)]: Constructor called.\n";
#endif
    }

    Discount_Quote(const Discount_Quote &other):
        Quote(other),
        discount(other.discount),
        quantity(other.quantity)
    {
#ifndef NDEBUG
        std::cout << "(ABSTRACT BASE) [Discount_Quote(const Discount_Quote&)]: Copy Constructor called.\n";
#endif
    }

    Discount_Quote(Discount_Quote &&other) noexcept:
        Quote(std::move(other)),
        discount(discount),
        quantity(quantity)
    {
#ifndef NDEBUG
        std::cout << "(ABSTRACT BASE) [Discount_Quote(Discount_Quote&&)]: Move Constructor called.\n";
#endif
    }

    Discount_Quote& operator=(const Discount_Quote& rhs)
    {
#ifndef NDEBUG
        std::cout << "(ABSTRACT BASE) [Discount_Quote::operator=(const Discount_Quote&)]: Copy Assignment called.\n";
#endif
        if (this != &rhs)
        {
            this->Quote::operator=(rhs);
            discount = rhs.discount;
            quantity = rhs.quantity;
        }
        return *this;
    }

    Discount_Quote& operator=(Discount_Quote&& rhs) noexcept
    {
#ifndef NDEBUG
        std::cout << "(ABSTRACT BASE) [Discount_Quote::operator=(Discount_Quote&&)]: Move Assignment called.\n";
#endif
        if (this != &rhs)
        {
            this->Quote::operator=(std::move(rhs));
            discount = rhs.discount;
            quantity = rhs.quantity;
        }

        return *this;
    }

    virtual ~Discount_Quote() = default;
    virtual double net_price(size_t) const = 0;
    
protected:
    double discount = 0.0;
    size_t quantity = 0;

    friend bool operator==(const Discount_Quote &lhs, const Discount_Quote &rhs)
    {
        if (!(static_cast<const Quote&>(lhs) == static_cast<const Quote&>(rhs)))
            return false;
        
        return lhs.discount == rhs.discount && lhs.quantity == rhs.quantity;
    }

};

class Bulk_Item: public Discount_Quote 
{
    // apply discount if quantity >= N
public:
    Bulk_Item() = default;
    Bulk_Item(const std::string &bbook, const double &bsales_price, const size_t &bmax_qty, const double &bdiscount):
        Discount_Quote(bbook, bsales_price, bdiscount, bmax_qty)
    {
#ifndef NDEBUG
        std::cout << "(DERIVED) [Bulk_Item(const string&, const double, const size_t &, const double &)]: Constructor called.\n";
#endif
    }

    Bulk_Item(const Bulk_Item& other):
        Discount_Quote(other)
    {
#ifndef NDEBUG
        std::cout << "(DERIVED) [Bulk_Item(const Bulk_Item&)]: Copy Constructor called.\n";
#endif
    }
    Bulk_Item(Bulk_Item&& other) noexcept: 
        Discount_Quote(std::move(other))
    {
#ifndef NDEBUG
        std::cout << "(DERIVED) [Bulk_Item(Bulk_Item&&)]: Move Constructor called.\n";
#endif
    }

    Bulk_Item& operator=(const Bulk_Item& rhs)
    {
#ifndef NDEBUG
        std::cout << "(DERIVED) [Bulk_Item::operator=(const Bulk_Item&)]: Copy Assignmnet called.\n";
#endif
        if (this != &rhs)
        {
            this->Discount_Quote::operator=(rhs);
        }
        
        return *this;
    }
    
    Bulk_Item& operator=(Bulk_Item&& rhs) noexcept
    {
#ifndef NDEBUG
        std::cout << "(DERIVED) [Bulk_Item::operator=(Bulk_Item&&)]: Move Assignment called.\n";
#endif
        if (this != &rhs)
        {
            this->Discount_Quote::operator=(std::move(rhs));
        }
        return *this;
    }

    virtual Bulk_Item* clone() const & {return new Bulk_Item(*this);}
    virtual Bulk_Item* clone() && { return new Bulk_Item(std::move(*this)); }

    virtual ~Bulk_Item() = default;
    virtual double net_price(size_t n) const override
    {
        if (n >= quantity)
            return (n * price) * (1.0 - discount);
        else 
            return Quote::net_price(n);
    }


    friend bool operator==(const Bulk_Item &lhs, const Bulk_Item &rhs)
    {
        return static_cast<const Discount_Quote&>(lhs) == static_cast<const Discount_Quote&>(rhs);
    }
};

double print_total(std::ostream &out, const Quote& quote, size_t copies)
{
    double ret = quote.net_price(copies);
    out << "Book with ISBN: " << quote.get_isbn() << " sold #" << copies << " copies."
        << " Total due: " << ret << std::endl;

    return ret;
}


class Basket
{
public:

    void add_item(const Quote& quote) {basket.insert(std::shared_ptr<Quote>(quote.clone()));}
    void add_item(Quote&& quote) {basket.insert(std::shared_ptr<Quote>(std::move(quote).clone()));}

    double total_receipt(std::ostream& out)
    {
        double sum = 0.0;

        for (auto iter = basket.cbegin(); iter != basket.cend(); iter = basket.upper_bound(*iter))
        {
            sum += print_total(std::cout, **iter, basket.count(*iter));
        }

        std::cout << "TOTAL BASKET DUE: " << sum << std::endl;
        return sum;
    }
private:

    struct compare // functor for multimap key comparison
    {
        bool operator()(const std::shared_ptr<Quote> &lhs, const std::shared_ptr<Quote> &rhs) const
        {
            return lhs->get_isbn() < rhs->get_isbn();
        }
    };

    std::multiset<std::shared_ptr<Quote>, compare> basket;

};

int main()
{

    Basket basket;
    
    basket.add_item(Bulk_Item("123", 15.0, 5, .30));
    basket.add_item(Bulk_Item("456", 1.0, 100, .20));


    std::cout << "Total amount due for purchases is: " << basket.total_receipt(std::cout) << " €\n";

    return EXIT_SUCCESS;    
}
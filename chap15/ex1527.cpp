#include <iostream>
#include <string>

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
    
    // inheriting constructors
    using Discount_Quote::Discount_Quote;
    
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

std::ostream& print_total(std::ostream &out, const Quote& quote, size_t copies)
{
    out << "Book with ISBN: " << quote.get_isbn() << " sold #" << copies << " copies."
        << " Total due: " << quote.net_price(copies) << std::endl;

    return out;
}

int main()
{
    
    // Now, parameter order must match the Discount_Quote ctor!!!
    Bulk_Item bq("1111-2222-3333", 1.0, .50, 100);

    print_total(std::cout, bq, 100); // 50 
    print_total(std::cout, bq, 80); // 80
    
    return EXIT_SUCCESS;    
}
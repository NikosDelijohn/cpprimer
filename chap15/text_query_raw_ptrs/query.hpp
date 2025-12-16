#pragma once

#include <string>
#include <memory>
#include <iostream>

class Query_Result;
class Text_Query;
class Base_Query;
class Word_Query;
class Not_Query;
class And_Query;
class Or_Query;
class Xor_Query;


class Query
{
    friend Query operator~(const Query &);
    friend Query operator&(const Query &, const Query &);
    friend Query operator|(const Query &, const Query &);
    friend Query operator^(const Query &, const Query &);

public:

    Query(const std::string &);
    ~Query();
    Query(const Query &);
    Query(Query &&) noexcept;
    Query& operator=(const Query &);
    Query& operator=(Query &&) noexcept;

    // These are NOT virtual classes. This is an interface.
    Query_Result eval(const Text_Query &) const;
    std::string rep() const;

private:
    Query(Base_Query *);
    Base_Query *q;
};

std::ostream& operator<<(std::ostream&, const Query &);
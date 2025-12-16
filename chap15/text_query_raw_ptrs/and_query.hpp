#pragma once

#include "binary_query.hpp"

class Query;
class Query_Result;
class Text_Query;

class And_Query: public Binary_Query
{
    friend Query operator&(const Query&, const Query&);

private:

    And_Query(const Query &, const Query &);
    virtual Query_Result eval(const Text_Query&) const override;
    virtual And_Query* clone() const override;
};

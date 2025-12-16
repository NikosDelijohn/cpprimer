#pragma once

#include "binary_query.hpp"

class Query_Result;

class Xor_Query: public Binary_Query
{

    friend Query operator^(const Query&, const Query&);

private:

    Xor_Query(const Query &, const Query &);
    virtual Query_Result eval(const Text_Query &) const override;
    virtual Xor_Query* clone() const override;
};
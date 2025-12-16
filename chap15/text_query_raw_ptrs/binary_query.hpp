#pragma once

#include "base_query.hpp"
#include "query.hpp"

class Binary_Query: public Base_Query
{

protected:

    Binary_Query(const Query &, const Query &, const std::string &);

    virtual std::string rep() const override;
    virtual Query_Result eval(const Text_Query &) const override = 0;

    Query lhs, rhs;
    std::string op;

};
#pragma once

#include "binary_query.hpp"

class Query;
class Text_Query;   
class Query_Result;

class Or_Query: public Binary_Query
{
    friend Query operator|(const Query&, const Query&);

private:

    Or_Query(const Query &, const Query &);
    virtual Query_Result eval(const Text_Query &) const override;

};
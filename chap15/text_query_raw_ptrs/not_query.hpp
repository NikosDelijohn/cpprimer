#pragma once

#include "base_query.hpp"
#include "query.hpp"

class Text_Query;
class Query;

class Not_Query: public Base_Query
{
    friend Query operator~(const Query &);

private:

    Not_Query(const Query &);
    
    virtual Query_Result eval(const Text_Query&) const override;
    virtual std::string rep() const override;
    virtual Not_Query* clone() const override;

    Query query;
};


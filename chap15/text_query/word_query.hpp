#pragma once

#include <iostream>
#include <string>

#include "base_query.hpp"

class Query;
class Text_Query;   
class Query_Result;

class Word_Query: public Base_Query
{  
    friend class Query;

private:

    Word_Query(const std::string &);
    
    virtual Query_Result eval(const Text_Query &) const override;
    virtual std::string rep() const override;

    std::string query_word;

};
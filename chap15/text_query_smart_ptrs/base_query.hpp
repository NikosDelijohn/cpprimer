#pragma once

#include "text_query.hpp"

class Base_Query
{
    friend class Query;

protected:

    using line_no = Text_Query::line_no;
    virtual ~Base_Query() = default;

private:

    virtual Query_Result eval(const Text_Query&) const = 0;
    virtual std::string rep() const = 0;

};

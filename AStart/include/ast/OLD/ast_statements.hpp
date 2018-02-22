#ifndef ast_statememts_hpp
#define ast_statememts_hpp

#include "ast_body.hpp"

#include <cmath>

class Statement
    : public Body
{
private:
    BodyPtr arg;
protected:
    Statement(BodyPtr _arg)
        : arg(_arg)
    {}
public:
    virtual const char * getStatement() const =0;

    BodyPtr getArg() const
    { return arg; }

    virtual void print(std::ostream &dst) const override
    {
        dst<<getStatement()<<"( ";
        arg->print(dst);
        dst<<" )";
    }
};

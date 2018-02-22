#ifndef ast_statememts_hpp
#define ast_statememts_hpp

#include "ast_body.hpp"

#include <cmath>

class Statement
    : public Body
{
private:
    //type
    //value of type above
protected:
    Function(BodyPtr _statem)
    {}
public:
    virtual const char * getFunction() const =0;

    virtual void print(std::ostream &dst) const =0;
    }
};

class ReturnStatement
: public Statement
{
public:
    ReturnStatement(){}
    
    virtual const char *getFunction() const
    { return "retrun"; }
    
    virtual double evaluate(
        const std::map<std::string,double> &bindings
    ) const override
    {
        double v=getArg()->evaluate(bindings);
        return log(v);
    }
};

#ifndef ast_functions_hpp
#define ast_functions_hpp

#include "ast_main_body.hpp"
#include "ast_body"

#include <cmath>

class Function
{
private:
    String funcId;
    ArgsPtr args;
    BodyPtr funcBody;
protected:
    Function(String _funcId, ArgsPtr _args, BodyPtr _funcBody)
        : funcID(_funcId)
        : args(_args)
        : funcBody(_funcBody)
    {}
public:
    String getFuncID() const
    { return funcId; }
    
    ArgsPtr getArgs() const
    { return args; }

    BodyPtr getFuncBody() const
    { return funcBody; }

    virtual void print(std::ostream &dst) const override{
        dst<<getFuncID()<<"(";
        args->print(dst);
        dst<<")";
        dst<<"{";
        funcBody->print(dst);
        dst<<"}"
    };

    virtual void translate(std::ostream &dst) const =0;
};

class Main
    : public Function
{
public:

};

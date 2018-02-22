#ifndef ast_functions_hpp
#define ast_functions_hpp

#include "ast_main_body.hpp"
#include "ast_body"

#include <cmath>

class Function
    : public MainBody
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
    virtual void print(std::ostream &dst) const =0;

    virtual void translate(std::ostream &dst) const =0;
};

class Main
: public Function
{
private:
    
public:
    virtual void print(std::ostream &dst) const override
    {
        dst<<"main( ";
        args->print(dst);
        dst<<" )";
    }
};

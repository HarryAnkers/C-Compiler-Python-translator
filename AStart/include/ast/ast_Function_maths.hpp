#ifndef ast_functions_hpp
#define ast_functions_hpp

#include "ast_expression.hpp"

#include <cmath>

class Function_maths
    : public Expression
{
private:
    ExpressionPtr arg;
protected:
    Function_maths(ExpressionPtr _arg)
        : arg(_arg)
    {}
public:
    virtual const char * getFunction() const =0;

    ExpressionPtr getArg() const
    { return arg; }

    virtual void print(std::ostream &dst) const override
    {
        dst<<getFunction()<<"( ";
        arg->print(dst);
        dst<<" )";
    }

    virtual double evaluate(
        const std::map<std::string,double> &bindings
    ) const override
    {
        // NOTE : This should be implemented by the inheriting function nodes, e.g. LogFunction
        throw std::runtime_error("FunctionOperator::evaluate is not implemented.");
    }
};

class LogFunction
: public Function_maths
{
public:
    LogFunction(ExpressionPtr _arg)
    : Function_maths(_arg)
    {}
    
    virtual const char *getFunction() const
    { return "log"; }
    
    virtual double evaluate(
        const std::map<std::string,double> &bindings
    ) const override
    {
        double v=getArg()->evaluate(bindings);
        return log(v);
    }
};

class ExpFunction
    : public Function_maths
{
public:
    ExpFunction(ExpressionPtr _arg)
        : Function_maths(_arg)
    {}

    virtual const char *getFunction() const
    { return "exp"; }
    
    virtual double evaluate(
        const std::map<std::string,double> &bindings
    ) const override
    {
        double v=getArg()->evaluate(bindings);
        return exp(v);
    }
};

class SqrtFunction
    : public Function_maths
{
public:
    SqrtFunction(ExpressionPtr _arg)
        : Function_maths(_arg)
    {}

    virtual const char *getFunction() const
    { return "sqrt"; }
    
    virtual double evaluate(
    const std::map<std::string,double> &bindings
        ) const override
    {
        double v=getArg()->evaluate(bindings);
        return pow(v,0.5);
    }
};


#endif

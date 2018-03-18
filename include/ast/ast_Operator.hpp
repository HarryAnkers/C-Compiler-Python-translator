#ifndef ast_Operators_hpp
#define ast_Operators_hpp

#include "ast_ASTNode.hpp"

#include <cmath>

class Operator
    : public ASTNode
{
protected:
    node left;
    node right;

    Operator(node _left, node _right)
        : left(_left)
        , right(_right)
    {}
public:
    virtual const char *getOpcode() const =0;
    virtual const char *getSignInst() const =0;
    virtual const char *getUnsignInst() const =0;

    virtual void print(std::ostream &dst, PrintTransState &state) const override
    {
        dst<<"(";
        left->print(dst, state);
        dst<<getOpcode();
        right->print(dst, state);
        dst<<")";
    }

    virtual void translate(std::ostream &dst, PrintTransState &state) const override{
        dst<<"(";
        left->translate(dst, state);
        dst<<getOpcode();
        right->translate(dst, state);
        dst<<")";
    }

    //compiler 
    virtual void compile(std::ostream &dst, CompilerState &state) const override{
        int reg2 = state.getTempReg(0);
        left->compile(dst, state);
        int reg3 = state.getTempReg(0);
        right->compile(dst, state);
        state.registers[reg2]=0;
        state.registers[reg3]=0;
        int reg1 = state.getTempReg(1);
        dst<<getSignInst()<<" "<<"$"<<reg1<<" , "<<"$"<<reg2<<" , "<<"$"<<reg3<<std::endl;
    }
};

class AddOperator
    : public Operator
{
protected:
    virtual const char *getOpcode() const override
    { return "+"; }

    virtual const char *getSignInst() const override
    { return "add"; }

    virtual const char *getUnsignInst() const override
    { return "addu"; }
public:
    AddOperator(node _left, node _right)
        : Operator(_left, _right)
    {}
    
};

class SubOperator
    : public Operator
{
protected:
    virtual const char *getOpcode() const override
    { return "-"; }

    virtual const char *getSignInst() const override
    { return "sub"; }

    virtual const char *getUnsignInst() const override
    { return "subu"; }
public:
    SubOperator(node _left, node _right)
        : Operator(_left, _right)
    {}
};


class MulOperator
    : public Operator
{
protected:
    virtual const char *getOpcode() const override
    { return "*"; }

    virtual const char *getSignInst() const override
    { return "mult"; }

    virtual const char *getUnsignInst() const override
    { return "multu"; }
public:
    MulOperator(node _left, node _right)
        : Operator(_left, _right)
    {}
};

class DivOperator
    : public Operator
{
protected:
    virtual const char *getOpcode() const override
    { return "/"; }

    virtual const char *getSignInst() const override
    { return "div"; }

    virtual const char *getUnsignInst() const override
    { return "divu"; }
public:
    DivOperator(node _left, node _right)
        : Operator(_left, _right)
    {}
};

class ExpOperator
    : public Operator
{
protected:
    virtual const char *getOpcode() const override
    { return "^"; }

    //need to impliment the below
    virtual const char *getSignInst() const override
    { return "NOT IMPIMENTED"; }

    virtual const char *getUnsignInst() const override
    { return "NOT IMPIMENTED"; }
public:
    ExpOperator(node _left, node _right)
        : Operator(_left, _right)
    {}
};


#endif

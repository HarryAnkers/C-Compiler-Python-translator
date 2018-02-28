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

    virtual void print(std::ostream &dst, int &indent) const override
    {
        dst<<"( ";
        left->print(dst,indent);
        dst<<" ";
        dst<<getOpcode();
        dst<<" ";
        right->print(dst,indent);
        dst<<" )";
    }

    virtual void translate(std::ostream &dst, int &indent) const {
        dst<<"( ";
        left->translate(dst,indent);
        dst<<" ";
        dst<<getOpcode();
        dst<<" ";
        right->translate(dst,indent);
        dst<<" )";
    }

    //compiler 
    virtual void compile(std::ostream &dst) const override{}
};

class AddOperator
    : public Operator
{
protected:
    virtual const char *getOpcode() const override
    { return "+"; }
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
public:
    ExpOperator(node _left, node _right)
        : Operator(_left, _right)
    {}
};


#endif

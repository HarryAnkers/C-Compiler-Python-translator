#ifndef ast_Primitives_hpp
#define ast_Primitives_hpp

#include "ast_ASTNode.hpp"

class Variable
    : public ASTNode
{
private:
    std::string id;
public:
    Variable(const std::string &_id)
        : id(_id)
    {}

    const std::string getId() const
    { return id; }

    virtual void print(std::ostream &dst) const override{
        dst<<id;
    }

    virtual void translate(std::ostream &dst) const override{
        dst<<id;
    }

    virtual void compile(std::ostream &dst, int &indent) const override{}
};

class Number
    : public ASTNode
{
private:
    double value;
public:
    Number(double _value)
        : value(_value)
    {}

    double getValue() const
    { return value; }

    virtual void print(std::ostream &dst) const override{
        dst<<value;
    }

    virtual void translate(std::ostream &dst) const override{
        dst<<value;
    }

    virtual void compile(std::ostream &dst, int &indent) const override{}
};

class String
    : public ASTNode
{
public:
    std::string value;
    String(std::string _value)
        : value(_value)
    {}

    virtual void print(std::ostream &dst) const override{
        dst<<value;
    }

    virtual void translate(std::ostream &dst) const override{
        dst<<value;
    }

    virtual void compile(std::ostream &dst, int &indent) const override{}
};

class Char
    : public ASTNode
{
public:
    char value;
    Char(char _value)
        : value(_value)
    {}

    virtual void print(std::ostream &dst) const override{
        dst<<value;
    }

    virtual void translate(std::ostream &dst) const override{
        dst<<value;
    }

    virtual void compile(std::ostream &dst, int &indent) const override{}
};

#endif

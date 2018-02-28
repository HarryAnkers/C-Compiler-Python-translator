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

    virtual void print(std::ostream &dst, int &indent) const override{
        dst<<id;
    }

    virtual void translate(std::ostream &dst, int &indent) const override{
        dst<<id;
    }

    virtual void compile(std::ostream &dst) const override{}
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

    virtual void print(std::ostream &dst, int &indent) const override{
        dst<<value;
    }

    virtual void translate(std::ostream &dst, int &indent) const override{
        dst<<value;
    }

    virtual void compile(std::ostream &dst) const override{}
};

class String
    : public ASTNode
{
public:
    std::string value;
    String(std::string _value)
        : value(_value)
    {}

    virtual void print(std::ostream &dst, int &indent) const override{
        dst<<value;
    }

    virtual void translate(std::ostream &dst, int &indent) const override{
        dst<<value;
    }

    virtual void compile(std::ostream &dst) const override{}
};

class FunctionStatementInExpr : public ASTNode
{
    public:
        std::string id;
        node arguments;

        FunctionStatementInExpr(std::string &_id, node _arguments):
        id(_id), arguments(_arguments){}

        //print tester
        virtual void print(std::ostream &dst, int &indent) const override
        {
            for(int i=indent;i!=0;i--){
                dst<<"\t";
            }
            dst<<id<<"(";
            arguments->print(dst,indent);
            dst<<")";
        }

        //translator 
        virtual void translate(std::ostream &dst, int &indent) const override{
            for(int i=indent;i!=0;i--){
                dst<<"\t";
            }
            dst<<id<<"(";
            arguments->translate(dst,indent);
            dst<<")";
        }

        //compiler 
        virtual void compile(std::ostream &dst) const override{}
};

#endif

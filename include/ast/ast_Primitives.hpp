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

    virtual void print(std::ostream &dst, PrintTransState &state) const override{
        dst<<id;
    }

    virtual void translate(std::ostream &dst, PrintTransState &state) const override{
        dst<<id;
    }

    virtual void compile(std::ostream &dst, CompilerState &state) const override{
        for(int i = state.varVector.size()-1;i>=0;i--){
            if(!state.varVector[i].id.compare(id)){
                int regNo = state.getTempReg(1);
                dst<<"lw "<<"$"<<regNo<<" , "<<state.varVector[i].stackOffset<<"($fp)"<<std::endl;
                return;
            }
        }
        throw std::invalid_argument( "variable used was not found (previously declared)" );
    }
};

class Number
    : public ASTNode
{
private:
    double value;
public:
    Number(double pos, double neg)
        : value(pos-neg)
    {}

    double getValue() const
    { return value; }

    virtual void print(std::ostream &dst, PrintTransState &state) const override{
        dst<<value;
    }

    virtual void translate(std::ostream &dst, PrintTransState &state) const override{
        dst<<value;
    }

    virtual void compile(std::ostream &dst, CompilerState &state) const override{
        int reg1 = state.getTempReg(1);
        dst<<"addi"<<" "<<"$"<<reg1<<" , "<<"$"<<"0"<<" , "<<"0x"<<state.toHex(value)<<std::endl;
    }
};


#endif

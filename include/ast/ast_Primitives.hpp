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
        for(int i = state.gloVarVector.size()-1;i>=0;i--){
            if(!state.gloVarVector[i].id.compare(id)){
                int regNo = state.getTempReg(1);
                dst<<"lui "<<"$"<<regNo<<" , "<<"%hi("<<id<<")"<<std::endl;
                dst<<"lw "<<"$"<<regNo<<" , "<<"%lo("<<id<<")($"<<regNo<<")"<<std::endl;
                return;
            }
        }
        throw std::invalid_argument( "variable used was not found (previously declared)" );
    }

    virtual void count(CompilerState &state) const override {}
};

class Number
    : public ASTNode
{
private:
    float value;
public:
    Number(float pos, float neg)
        : value(pos-neg)
    {}

    float getValue() const
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

    virtual void count(CompilerState &state) const override {}
};


#endif

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
                int regNo = state.getTempReg(1,dst);
                dst<<"lw "<<"$"<<regNo<<" , "<<state.varVector[i].stackOffset<<"($fp)"<<std::endl;
                state.ifFull(dst);
                return;
            }
        }
        for(int i = state.gloVarVector.size()-1;i>=0;i--){
            if(!state.gloVarVector[i].id.compare(id)){
                int regNo = state.getTempReg(1,dst);
                dst<<"lui "<<"$"<<regNo<<" , "<<"%hi("<<id<<")"<<std::endl;
                dst<<"lw "<<"$"<<regNo<<" , "<<"%lo("<<id<<")($"<<regNo<<")"<<std::endl;
                state.ifFull(dst);
                return;
            }
        }
        throw std::invalid_argument( "variable used ["+id+"] was not found (previously declared) @variable" );
    }

    virtual void count(CompilerState &state) const override {}
};

class ArrayVal
    : public ASTNode
{
private:
    std::string id;
    int arrayId;
public:
    ArrayVal(const std::string &_id,int _arrayId)
        : id(_id), arrayId(_arrayId)
    {}

    const std::string getId() const
    { return id; }

    virtual void print(std::ostream &dst, PrintTransState &state) const override{
        dst<<id<<"["<<arrayId<<"]";
    }

    virtual void translate(std::ostream &dst, PrintTransState &state) const override{
        dst<<id<<"["<<arrayId<<"]";;
    }

    virtual void compile(std::ostream &dst, CompilerState &state) const override{
        for(int i = state.ArrayVector.size()-1;i>=0;i--){
            if(!state.ArrayVector[i].id.compare(id)){
                int reg1 = state.getTempReg(1,dst);

                dst<<"lw "<<"$"<<reg1<<" , "<<state.ArrayVector[i].elementOffset[arrayId]<<"($fp)"<<std::endl;
                state.ifFull(dst);
                return;
            }
        }
        throw std::invalid_argument( "variable used ["+id+"] was not found (previously declared) @arrayval" );
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
        int reg1 = state.getTempReg(1,dst);
        dst<<"addiu"<<" "<<"$"<<reg1<<" , "<<"$"<<"0"<<" , "<<"0x"<<state.toHex(value)<<std::endl;
        state.ifFull(dst);
    }

    virtual void count(CompilerState &state) const override {}
};


#endif

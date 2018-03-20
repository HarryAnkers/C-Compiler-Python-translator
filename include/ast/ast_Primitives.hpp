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
        dst<<"addi"<<" "<<"$"<<reg1<<" , "<<"$"<<"0"<<" , "<<"0x"<<value<<std::endl;
    }
};

class SizeOf
    : public ASTNode
{
public:
    std::string id;
    SizeOf(std::string _id)
        : id(_id)
    {}

    virtual void print(std::ostream &dst, PrintTransState &state) const override{
        dst<<"(size of "<<id<<")";
    }

    virtual void translate(std::ostream &dst, PrintTransState &state) const override{
        dst<<"(size of "<<id<<")";
    }

    virtual void compile(std::ostream &dst, CompilerState &state) const override{
        for(int i = state.varVector.size()-1;i>=0;i--){
            if(!state.varVector[i].id.compare(id)){
                int reg1 = state.getTempReg(0);
                int size = 0;
                if(state.varVector[i].type.compare("int")){size = 4;}
                else if(state.varVector[i].type.compare("unsigned int")){size = 4;}
                else if(state.varVector[i].type.compare("double")){size = 8;}
                else if(state.varVector[i].type.compare("long")){size = 8;}
                else{throw std::invalid_argument( "type size not defined" );}
                dst<<"addi"<<" "<<"$"<<reg1<<" , "<<"$"<<"0"<<" , "<<"0x"<<size<<std::endl;
                return;
            }
        }
        throw std::invalid_argument( "variable used was not found (previously declared)" );
    }
};

class FunctionStatementInExpr : public ASTNode
{
    public:
        std::string id;
        node arguments;

        FunctionStatementInExpr(std::string &_id, node _arguments):
        id(_id), arguments(_arguments){}

        //print tester
        virtual void print(std::ostream &dst, PrintTransState &state) const override{
            dst<<id<<"(";
            arguments->print(dst, state);
            dst<<")";
        }

        //translator 
        virtual void translate(std::ostream &dst, PrintTransState &state) const override{
            dst<<id<<"(";
            arguments->translate(dst, state);
            dst<<")";
        }

        //compiler 
        virtual void compile(std::ostream &dst, CompilerState &state) const override{}
};

#endif

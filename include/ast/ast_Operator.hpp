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
    // Looks like we still need a function to differentiate 
    // between getSignInst() and getUnsignInst()?
    virtual void compile(std::ostream &dst, CompilerState &state) const override{
        int reg2 = state.getTempReg(0);
        left->compile(dst, state);
        int reg3 = state.getTempReg(0);
        right->compile(dst, state);
        state.registers[reg2]=0;
        state.registers[reg3]=0;
        int reg1 = state.getTempReg(1);

        std::string type = getOpcode();
        if(type.compare("*")){
            dst<<getSignInst()<<" "<<"$"<<reg2<<" , "<<"$"<<reg3<<std::endl;
            dst<<"mflo"<<" "<<"$"<<reg1<<std::endl;
        } else if(type.compare("/")){
            dst<<getSignInst()<<" "<<"$"<<reg2<<" , "<<"$"<<reg3<<std::endl;
            dst<<"mflo"<<" "<<"$"<<reg1<<std::endl;
        } else if(type.compare("%")){
            dst<<getSignInst()<<" "<<"$"<<reg2<<" , "<<"$"<<reg3<<std::endl;
            dst<<"mfhi"<<" "<<"$"<<reg1<<std::endl;
        } else{
            dst<<getSignInst()<<" "<<"$"<<reg1<<" , "<<"$"<<reg2<<" , "<<"$"<<reg3<<std::endl;
        }
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

class ModOperator
    : public Operator
{
protected:
    virtual const char *getOpcode() const override
    { return "%"; }

    virtual const char *getSignInst() const override
    { return "div"; }

    virtual const char *getUnsignInst() const override
    { return "divu"; }
public:
    ModOperator(node _left, node _right)
        : Operator(_left, _right)
    {}
};

class BAnd
    : public Operator
{
protected:
    virtual const char *getOpcode() const override
    { return "&"; }

    virtual const char *getSignInst() const override
    { return "and"; }

    virtual const char *getUnsignInst() const override
    { return "and"; }
public:
    BAnd(node _left, node _right)
        : Operator(_left, _right)
    {}
};

class BOr
    : public Operator
{
protected:
    virtual const char *getOpcode() const override
    { return "|"; }

    virtual const char *getSignInst() const override
    { return "or"; }

    virtual const char *getUnsignInst() const override
    { return "or"; }
public:
    BOr(node _left, node _right)
        : Operator(_left, _right)
    {}
};

class BXor
    : public Operator
{
protected:
    virtual const char *getOpcode() const override
    { return "^"; }

    virtual const char *getSignInst() const override
    { return "xor"; }

    virtual const char *getUnsignInst() const override
    { return "xor"; }
public:
    BXor(node _left, node _right)
        : Operator(_left, _right)
    {}
};

class BNot
    : public Operator
{
protected:
    virtual const char *getOpcode() const override
    { return "~"; }

    virtual const char *getSignInst() const override
    { return "nor"; }

    virtual const char *getUnsignInst() const override
    { return "nor"; }
public:
    BNot(node _left)
        : Operator(_left, _left)
    {}
};

class BLShift
    : public Operator
{
protected:
    virtual const char *getOpcode() const override
    { return "<<"; }

    virtual const char *getSignInst() const override
    { return "sllv"; }

    virtual const char *getUnsignInst() const override
    { return "sllv"; }
public:
    BLShift(node _left, node _right)
        : Operator(_left, _right)
    {}
};

class BRShift
    : public Operator
{
protected:
    virtual const char *getOpcode() const override
    { return ">>"; }

    virtual const char *getSignInst() const override
    { return "srlv"; }

    virtual const char *getUnsignInst() const override
    { return "srlv"; }
public:
    BRShift(node _left, node _right)
        : Operator(_left, _right)
    {}
};

class AssignOp
    : public ASTNode
{
    public:
        std::string id;
        node expression;

        AssignOp(std::string &_id, node _expression):
        id(_id), expression(_expression){}

        //print tester
        virtual void print(std::ostream &dst, PrintTransState &state) const override
        {
            dst<<id<<"=";
            expression->print(dst, state);
        }

        //translator 
        virtual void translate(std::ostream &dst, PrintTransState &state) const override{
            dst<<id<<"=";
            expression->translate(dst, state);
        }

        //compiler 
        virtual void compile(std::ostream &dst, CompilerState &state) const override{
            for(int i = state.varVector.size()-1;i>=0;i--){
                if(!state.varVector[i].id.compare(id)){
                    int reg1 = state.getTempReg(0);
                    expression->compile(dst,state);
                    dst<<"sw"<<" "<<"$"<<reg1<<" , "<<state.varVector[i].stackOffset<<"($fp)"<<std::endl;
                    return;
                }
            }
            throw std::invalid_argument( "variable used was not found (previously declared)" );
        }
};


#endif

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

    //for frame size
        void count(CompilerState &state) const override {
            left->count(state);
            right->count(state);
        }

    //compiler
    // Looks like we still need a function to differentiate 
    // between getSignInst() and getUnsignInst()?
    virtual void compile(std::ostream &dst, CompilerState &state) const override{
        int reg2 = state.getTempReg(0,dst);
        left->compile(dst, state);
        state.ifLoad(dst,reg2);
        int reg3 = state.getTempReg(0,dst);
        right->compile(dst, state);
        state.ifLoad(dst,reg3);
        state.registers[reg2]=0;
        state.registers[reg3]=0;
        int reg1 = state.getTempReg(1,dst);

        std::string type = getOpcode();
        if(!type.compare("*")){
            dst<<getSignInst()<<" "<<"$"<<reg2<<" , "<<"$"<<reg3<<std::endl;
            dst<<"mflo"<<" "<<"$"<<reg1<<std::endl;
        } else if(!type.compare("/")){
            dst<<"teq $"<<reg3<<",$0,7";
            dst<<getSignInst()<<" "<<"$"<<reg2<<" , "<<"$"<<reg3<<std::endl;
            dst<<"mflo"<<" "<<"$"<<reg1<<std::endl;
        } else if(!type.compare("%")){
            dst<<getSignInst()<<" "<<"$"<<reg2<<" , "<<"$"<<reg3<<std::endl;
            dst<<"mfhi"<<" "<<"$"<<reg1<<std::endl;
        } else{
            dst<<getSignInst()<<" "<<"$"<<reg1<<" , "<<"$"<<reg2<<" , "<<"$"<<reg3<<std::endl;
        }
        state.ifFull(dst);
    }
};

class AddOperator
    : public Operator
{
protected:
    virtual const char *getOpcode() const override
    { return "+"; }

    virtual const char *getSignInst() const override
    { return "addu"; }

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
    { return "subu"; }

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
    { return "mult"; }
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
    { return "sll"; }

    virtual const char *getUnsignInst() const override
    { return "sll"; }
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
    { return "sra"; }

    virtual const char *getUnsignInst() const override
    { return "srl"; }
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
        int arrayId;
        node expression;

        AssignOp(std::string &_id, node _expression):
        id(_id),arrayId(-1), expression(_expression){}

        AssignOp(std::string &_id, int _arrayId, node _expression):
        id(_id), arrayId(_arrayId), expression(_expression){}

        //print tester
        virtual void print(std::ostream &dst, PrintTransState &state) const override
        {
            if(arrayId==-1){ dst<<id<<"="; }
            else { dst<<id<<"["<<arrayId<<"]"<<"="; }
            expression->print(dst, state);
        }

        //translator 
        virtual void translate(std::ostream &dst, PrintTransState &state) const override{
            if(arrayId==-1){ dst<<id<<"="; }
            else { dst<<id<<"["<<arrayId<<"]"<<"="; }
            expression->translate(dst, state);
        }

        //compiler 
        virtual void compile(std::ostream &dst, CompilerState &state) const override{
            if(arrayId!=-1){
                for(int i = state.ArrayVector.size()-1;i>=0;i--){
                    if(!state.ArrayVector[i].id.compare(id)){
                        int reg1 = state.getTempReg(0,dst);
                        expression->compile(dst,state);
                        state.ifLoad(dst,reg1);
                        dst<<"sw"<<" "<<"$"<<reg1<<" , "<<state.ArrayVector[i].elementOffset[arrayId]<<"($fp)"<<std::endl;
                        state.ifFull(dst); 
                        return;
                    }
                }
            } else {
                for(int i = state.varVector.size()-1;i>=0;i--){
                    if(!state.varVector[i].id.compare(id)){
                        int reg1 = state.getTempReg(0,dst);
                        expression->compile(dst,state);
                        state.ifLoad(dst,reg1);
                        dst<<"sw"<<" "<<"$"<<reg1<<" , "<<state.varVector[i].stackOffset<<"($fp)"<<std::endl;
                        state.ifFull(dst);
                        return;
                    }
                }
                for(int i = state.gloVarVector.size()-1;i>=0;i--){
                    if(!state.gloVarVector[i].id.compare(id)){
                        int reg1 = state.getTempReg(0,dst);
                        expression->compile(dst,state);
                        state.ifLoad(dst,reg1);

                        dst<<"sw"<<" "<<"$"<<reg1<<" , "<<"%lo("<<id<<")("<<reg1<<")"<<std::endl;
                        state.ifFull(dst);
                        return;
                    }
                }
            }
            throw std::invalid_argument( "variable ["+id+"] used was not found (previously declared) @assign" );
        }

        //for frame size
        void count(CompilerState &state) const override {
            expression->count(state);
        }
};

class TenOp
    : public ASTNode
{
    public:
        node condition;
        node expression1;
        node expression2;

        TenOp(node _condition, node _expression1, node _expression2):
        condition(_condition), expression1(_expression1), expression2(_expression2){}

        //print tester
        virtual void print(std::ostream &dst, PrintTransState &state) const override
        {   
            dst<<"(";
            condition->print(dst,state);
            dst<<" ? ";
            expression1->print(dst,state);
            dst<<" : ";
            expression2->print(dst,state);
            dst<<")";
        }

        //translator 
        virtual void translate(std::ostream &dst, PrintTransState &state) const override{
            dst<<"(";
            condition->translate(dst,state);
            dst<<" ? ";
            expression1->translate(dst,state);
            dst<<" : ";
            expression2->translate(dst,state);
            dst<<")";
        }

        //compiler 
        virtual void compile(std::ostream &dst, CompilerState &state) const override{
            int reg1 = state.getTempReg(0,dst);
            int reg2;
            condition->compile(dst,state);
            state.ifLoad(dst,reg1);
            state.registers[reg1]=0;
            
            reg1 = state.getTempReg(1,dst);
            
            dst<<"beq"<<" "<<"$"<<reg1<<" , "<<"$"<<"0"<<" , "<<"$L"<<(state.labelId)<<std::endl;
            dst<<"nop"<<std::endl;

            reg2 = state.getTempReg(0,dst);
            expression1->compile(dst,state);
            state.ifLoad(dst,reg2);
            state.registers[reg2]=0;
            dst<<"addu"<<" "<<"$"<<reg1<<" , "<<"$"<<reg2<<" , "<<"$"<<"0"<<std::endl;


            dst<<"b"<<" "<<"$L"<<(state.labelId+1)<<std::endl;
            dst<<"nop"<<std::endl;

            dst<<"$L"<<state.label()<<std::endl;

            reg2 = state.getTempReg(0,dst);
            expression2->compile(dst,state);
            state.ifLoad(dst,reg2);
            state.registers[reg2]=0;
            dst<<"addu"<<" "<<"$"<<reg1<<" , "<<"$"<<reg2<<" , "<<"$"<<"0"<<std::endl;

            dst<<"$L"<<state.label()<<std::endl;
            state.ifFull(dst);
        }

        //for frame size
        void count(CompilerState &state) const override {
            condition->count(state);
            expression1->count(state);
            expression2->count(state);
        }
};

class CommaOp
    : public ASTNode
{
    public:
        node expression1;
        node expression2;

        CommaOp(node _expression1, node _expression2):
        expression1(_expression1), expression2(_expression2){}

        //print tester
        virtual void print(std::ostream &dst, PrintTransState &state) const override
        {
            dst<<"(";
            expression1->print(dst,state);
            dst<<" , ";
            expression2->print(dst, state);
            dst<<")";
        }

        //translator 
        virtual void translate(std::ostream &dst, PrintTransState &state) const override{
            dst<<"(";
            expression1->translate(dst,state);
            dst<<" , ";
            expression2->translate(dst, state);
            dst<<")";
        }

        //compiler 
        virtual void compile(std::ostream &dst, CompilerState &state) const override{
            int reg1 = state.getTempReg(1,dst);
            int reg2 = state.getTempReg(0,dst);
            expression1->compile(dst,state);
            state.ifLoad(dst,reg2);
            state.registers[reg2]=0;
            
            reg2 = state.getTempReg(0,dst);
            expression2->compile(dst, state);
            state.registers[reg2]=0;
            dst<<"addu"<<" "<<"$"<<reg1<<" , "<<"$"<<reg2<<" , "<<"$"<<"0"<<std::endl;
            state.ifFull(dst);
        }

        //for frame size
        void count(CompilerState &state) const override {
            expression1->count(state);
            expression2->count(state);
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
        virtual void compile(std::ostream &dst, CompilerState &state) const override{
            for(unsigned int i=0;i<state.funcVector.size();i++){
                if(!state.funcVector[i].id.compare(id)){
                    state.currentArgCount=((signed)state.funcVector[i].arguments.size()-1);
                    state.currentArgSize=state.funcVector[i].argSize;
                    state.currentFCall=i;

                    arguments->compile(dst,state);
                    if(state.currentArgCount!=-1){
                        throw std::invalid_argument( "argument sizes don't match @funccall" );
                    }
                    dst<<"jal"<<" "<<state.funcVector[i].id<<std::endl;
                    dst<<"nop"<<std::endl;
                    int reg1 = state.getTempReg(1,dst);
                    if(state.funcVector[i].type.compare("void")){
                        dst<<"addu"<<" "<<"$"<<"2"<<" , "<<"$"<<reg1<<" , "<<"$0"<<std::endl<<std::endl;
                    }
                    state.ifFull(dst);
                    return;
                }
            }
            throw std::invalid_argument( "function["+id+"] not defined @funccall" );
        }

        //for frame size
        void count(CompilerState &state) const override {
            int argCount=0;
            int argSpace=0;
            std::string type;

            for(unsigned int i=0;i<state.funcVector.size();i++){
                if(!state.funcVector[i].id.compare(id)){
                    argCount=state.funcVector[i].arguments.size();
                    if(state.argCount>argCount){ state.argCount = argCount; }
                    for(int j=0;j<argCount;j++){
                        argSpace+=state.typeToSize(type=state.funcVector[i].arguments[j]);
                    }
                    if(argSpace>state.argSpace){
                        state.argSpace=argSpace;
                    }
                    return;
                }
            }
            throw std::invalid_argument( "function ["+id+"] not defined @funccall(count)" );
        }
};

class SizeOf
    : public ASTNode
{
public:
    std::string id;
    int arrayId;

    SizeOf(std::string _id)
        : id(_id), arrayId(-1)
    {}
    SizeOf(std::string _id,int _arrayId)
        : id(_id), arrayId(_arrayId)
    {}

    virtual void print(std::ostream &dst, PrintTransState &state) const override{
        if(arrayId==-1) { dst<<"(size of "<<id<<")"; }
        else { 
            dst<<"(size of "<<id<<"["<<arrayId<<"]"<<")"; 
        }
    }

    virtual void translate(std::ostream &dst, PrintTransState &state) const override{
        if(arrayId==-1) { dst<<"(size of "<<id<<")"; }
        else { 
            dst<<"(size of "<<id<<"["<<arrayId<<"]"<<")"; 
        }
    }

    virtual void compile(std::ostream &dst, CompilerState &state) const override{
        int reg1 = state.getTempReg(0,dst);
        std::string temp = id;
        int size=0;

        if(arrayId!=-1){
            for(int i = state.ArrayVector.size()-1;i>=0;i--){
                if(!state.ArrayVector[i].id.compare(id)){
                    
                    dst<<"addiu"<<" "<<"$"<<reg1<<" , "<<"$"<<"0"<<" , "<<"0x"<<state.toHex(state.typeToSize(state.ArrayVector[i].type))<<std::endl;
                    state.ifFull(dst);
                    return;
                }
            }
        }
        for(int i=0;i<15;i++){
            if(!temp.compare("char")){ size = 4;
                dst<<"addiu"<<" "<<"$"<<reg1<<" , "<<"$"<<"0"<<" , "<<"0x"<<state.toHex(size)<<std::endl;
                state.ifFull(dst);
                return; }
            else if(!temp.compare("signed char")){ size = 4;
                dst<<"addiu"<<" "<<"$"<<reg1<<" , "<<"$"<<"0"<<" , "<<"0x"<<state.toHex(size)<<std::endl;
                state.ifFull(dst);
                return; }
            else if(!temp.compare("unsigned char")){ size = 4;
                dst<<"addiu"<<" "<<"$"<<reg1<<" , "<<"$"<<"0"<<" , "<<"0x"<<state.toHex(size)<<std::endl;
                state.ifFull(dst);
                return; }
            else if(!temp.compare("short")){ size = 4;
                dst<<"addiu"<<" "<<"$"<<reg1<<" , "<<"$"<<"0"<<" , "<<"0x"<<state.toHex(size)<<std::endl;
                state.ifFull(dst);
                return; }
            else if(!temp.compare("unsigned short")){ size = 4;
                dst<<"addiu"<<" "<<"$"<<reg1<<" , "<<"$"<<"0"<<" , "<<"0x"<<state.toHex(size)<<std::endl;
                state.ifFull(dst);
                return; }
            else if(!temp.compare("int")){ size = 4;
                dst<<"addiu"<<" "<<"$"<<reg1<<" , "<<"$"<<"0"<<" , "<<"0x"<<state.toHex(size)<<std::endl;
                state.ifFull(dst);
                return; }
            else if(!temp.compare("unsigned int")){ size = 4;
                dst<<"addiu"<<" "<<"$"<<reg1<<" , "<<"$"<<"0"<<" , "<<"0x"<<state.toHex(size)<<std::endl;
                state.ifFull(dst);
                return; }
            else if(!temp.compare("long")){ size = 8;
                dst<<"addiu"<<" "<<"$"<<reg1<<" , "<<"$"<<"0"<<" , "<<"0x"<<state.toHex(size)<<std::endl;
                state.ifFull(dst);
                return; }
            else if(!temp.compare("unsigned long")){ size = 8;
                dst<<"addiu"<<" "<<"$"<<reg1<<" , "<<"$"<<"0"<<" , "<<"0x"<<state.toHex(size)<<std::endl;
                state.ifFull(dst);
                return; }
            else if(!temp.compare("long long")){ size = 16;
                dst<<"addiu"<<" "<<"$"<<reg1<<" , "<<"$"<<"0"<<" , "<<"0x"<<state.toHex(size)<<std::endl;
                state.ifFull(dst);
                return; }
            else if(!temp.compare("unsigned long long")){ size = 16;
                dst<<"addiu"<<" "<<"$"<<reg1<<" , "<<"$"<<"0"<<" , "<<"0x"<<state.toHex(size)<<std::endl;
                state.ifFull(dst);
                return; }
            else if(!temp.compare("float")){ size = 4;
                dst<<"addiu"<<" "<<"$"<<reg1<<" , "<<"$"<<"0"<<" , "<<"0x"<<state.toHex(size)<<std::endl;
                state.ifFull(dst);
                return; }
            else if(!temp.compare("double")){ size = 8;
                dst<<"addiu"<<" "<<"$"<<reg1<<" , "<<"$"<<"0"<<" , "<<"0x"<<state.toHex(size)<<std::endl;
                state.ifFull(dst);
                return; }
            else if(!temp.compare("long double")){ size = 32;
                dst<<"addiu"<<" "<<"$"<<reg1<<" , "<<"$"<<"0"<<" , "<<"0x"<<state.toHex(size)<<std::endl;
                state.ifFull(dst);
                return; }
            else if(!temp.compare("void")){ size = 0;
                dst<<"addiu"<<" "<<"$"<<reg1<<" , "<<"$"<<"0"<<" , "<<"0x"<<state.toHex(size)<<std::endl;
                state.ifFull(dst);
                return; }
        }
        for(int i = state.varVector.size()-1;i>=0;i--){
            if(!state.varVector[i].id.compare(id)){
                temp = state.varVector[i].type;
                if(!temp.compare("char")){ size = 4;
                    dst<<"addiu"<<" "<<"$"<<reg1<<" , "<<"$"<<"0"<<" , "<<"0x"<<state.toHex(size)<<std::endl;
                    state.ifFull(dst);
                    return; }
                else if(!temp.compare("signed char")){ size = 4;
                    dst<<"addiu"<<" "<<"$"<<reg1<<" , "<<"$"<<"0"<<" , "<<"0x"<<state.toHex(size)<<std::endl;
                    state.ifFull(dst);
                    return; }
                else if(!temp.compare("unsigned char")){ size = 4;
                    dst<<"addiu"<<" "<<"$"<<reg1<<" , "<<"$"<<"0"<<" , "<<"0x"<<state.toHex(size)<<std::endl;
                    state.ifFull(dst);
                    return; }
                else if(!temp.compare("short")){ size = 4;
                    dst<<"addiu"<<" "<<"$"<<reg1<<" , "<<"$"<<"0"<<" , "<<"0x"<<state.toHex(size)<<std::endl;
                    state.ifFull(dst);
                    return; }
                else if(!temp.compare("unsigned short")){ size = 4;
                    dst<<"addiu"<<" "<<"$"<<reg1<<" , "<<"$"<<"0"<<" , "<<"0x"<<state.toHex(size)<<std::endl;
                    state.ifFull(dst);
                    return; }
                else if(!temp.compare("int")){ size = 4;
                    dst<<"addiu"<<" "<<"$"<<reg1<<" , "<<"$"<<"0"<<" , "<<"0x"<<state.toHex(size)<<std::endl;
                    state.ifFull(dst);
                    return; }
                else if(!temp.compare("unsigned int")){ size = 4;
                    dst<<"addiu"<<" "<<"$"<<reg1<<" , "<<"$"<<"0"<<" , "<<"0x"<<state.toHex(size)<<std::endl;
                    state.ifFull(dst);
                    return; }
                else if(!temp.compare("long")){ size = 8;
                    dst<<"addiu"<<" "<<"$"<<reg1<<" , "<<"$"<<"0"<<" , "<<"0x"<<state.toHex(size)<<std::endl;
                    state.ifFull(dst);
                    return; }
                else if(!temp.compare("unsigned long")){ size = 8;
                    dst<<"addiu"<<" "<<"$"<<reg1<<" , "<<"$"<<"0"<<" , "<<"0x"<<state.toHex(size)<<std::endl;
                    state.ifFull(dst);
                    return; }
                else if(!temp.compare("long long")){ size = 16;
                    dst<<"addiu"<<" "<<"$"<<reg1<<" , "<<"$"<<"0"<<" , "<<"0x"<<state.toHex(size)<<std::endl;
                    state.ifFull(dst);
                    return; }
                else if(!temp.compare("unsigned long long")){ size = 16;
                    dst<<"addiu"<<" "<<"$"<<reg1<<" , "<<"$"<<"0"<<" , "<<"0x"<<state.toHex(size)<<std::endl;
                    state.ifFull(dst);
                    return; }
                else if(!temp.compare("float")){ size = 4;
                    dst<<"addiu"<<" "<<"$"<<reg1<<" , "<<"$"<<"0"<<" , "<<"0x"<<state.toHex(size)<<std::endl;
                    state.ifFull(dst);
                    return; }
                else if(!temp.compare("double")){ size = 8;
                    dst<<"addiu"<<" "<<"$"<<reg1<<" , "<<"$"<<"0"<<" , "<<"0x"<<state.toHex(size)<<std::endl;
                    state.ifFull(dst);
                    return; }
                else if(!temp.compare("long double")){ size = 32;
                    dst<<"addiu"<<" "<<"$"<<reg1<<" , "<<"$"<<"0"<<" , "<<"0x"<<state.toHex(size)<<std::endl;
                    state.ifFull(dst);
                    return; }
                else if(!temp.compare("void")){ size = 0;
                    dst<<"addiu"<<" "<<"$"<<reg1<<" , "<<"$"<<"0"<<" , "<<"0x"<<state.toHex(size)<<std::endl;
                    state.ifFull(dst);
                    return; }
            }
        }
        for(int i = state.ArrayVector.size()-1;i>=0;i--){
            if(!state.ArrayVector[i].id.compare(id)){
                temp = state.ArrayVector[i].type;
                if(!temp.compare("char")){ size = 4;
                    size = size*state.ArrayVector[i].elementOffset.size();
                    dst<<"addiu"<<" "<<"$"<<reg1<<" , "<<"$"<<"0"<<" , "<<"0x"<<state.toHex(size)<<std::endl;
                    state.ifFull(dst);
                    return; }
                else if(!temp.compare("signed char")){ size = 4;
                    size = size*state.ArrayVector[i].elementOffset.size();
                    dst<<"addiu"<<" "<<"$"<<reg1<<" , "<<"$"<<"0"<<" , "<<"0x"<<state.toHex(size)<<std::endl;
                    state.ifFull(dst);
                    return; }
                else if(!temp.compare("unsigned char")){ size = 4;
                    size = size*state.ArrayVector[i].elementOffset.size();
                    dst<<"addiu"<<" "<<"$"<<reg1<<" , "<<"$"<<"0"<<" , "<<"0x"<<state.toHex(size)<<std::endl;
                    state.ifFull(dst);
                    return; }
                else if(!temp.compare("short")){ size = 4;
                    size = size*state.ArrayVector[i].elementOffset.size();
                    dst<<"addiu"<<" "<<"$"<<reg1<<" , "<<"$"<<"0"<<" , "<<"0x"<<state.toHex(size)<<std::endl;
                    state.ifFull(dst);
                    return; }
                else if(!temp.compare("unsigned short")){ size = 4;
                    size = size*state.ArrayVector[i].elementOffset.size();
                    dst<<"addiu"<<" "<<"$"<<reg1<<" , "<<"$"<<"0"<<" , "<<"0x"<<state.toHex(size)<<std::endl;
                    state.ifFull(dst);
                    return; }
                else if(!temp.compare("int")){ size = 4;
                    size = size*state.ArrayVector[i].elementOffset.size();
                    dst<<"addiu"<<" "<<"$"<<reg1<<" , "<<"$"<<"0"<<" , "<<"0x"<<state.toHex(size)<<std::endl;
                    state.ifFull(dst);
                    return; }
                else if(!temp.compare("unsigned int")){ size = 4;
                    size = size*state.ArrayVector[i].elementOffset.size();
                    dst<<"addiu"<<" "<<"$"<<reg1<<" , "<<"$"<<"0"<<" , "<<"0x"<<state.toHex(size)<<std::endl;
                    state.ifFull(dst);
                    return; }
                else if(!temp.compare("long")){ size = 8;
                    size = size*state.ArrayVector[i].elementOffset.size();
                    dst<<"addiu"<<" "<<"$"<<reg1<<" , "<<"$"<<"0"<<" , "<<"0x"<<state.toHex(size)<<std::endl;
                    state.ifFull(dst);
                    return; }
                else if(!temp.compare("unsigned long")){ size = 8;
                    size = size*state.ArrayVector[i].elementOffset.size();
                    dst<<"addiu"<<" "<<"$"<<reg1<<" , "<<"$"<<"0"<<" , "<<"0x"<<state.toHex(size)<<std::endl;
                    state.ifFull(dst);
                    return; }
                else if(!temp.compare("long long")){ size = 16;
                    size = size*state.ArrayVector[i].elementOffset.size();
                    dst<<"addiu"<<" "<<"$"<<reg1<<" , "<<"$"<<"0"<<" , "<<"0x"<<state.toHex(size)<<std::endl;
                    state.ifFull(dst);
                    return; }
                else if(!temp.compare("unsigned long long")){ size = 16;
                    size = size*state.ArrayVector[i].elementOffset.size();
                    dst<<"addiu"<<" "<<"$"<<reg1<<" , "<<"$"<<"0"<<" , "<<"0x"<<state.toHex(size)<<std::endl;
                    state.ifFull(dst);
                    return; }
                else if(!temp.compare("float")){ size = 4;
                    size = size*state.ArrayVector[i].elementOffset.size();
                    dst<<"addiu"<<" "<<"$"<<reg1<<" , "<<"$"<<"0"<<" , "<<"0x"<<state.toHex(size)<<std::endl;
                    state.ifFull(dst);
                    return; }
                else if(!temp.compare("double")){ size = 8;
                    size = size*state.ArrayVector[i].elementOffset.size();
                    dst<<"addiu"<<" "<<"$"<<reg1<<" , "<<"$"<<"0"<<" , "<<"0x"<<state.toHex(size)<<std::endl;
                    state.ifFull(dst);
                    return; }
                else if(!temp.compare("long double")){ size = 32;
                    size = size*state.ArrayVector[i].elementOffset.size();
                    dst<<"addiu"<<" "<<"$"<<reg1<<" , "<<"$"<<"0"<<" , "<<"0x"<<state.toHex(size)<<std::endl;
                    state.ifFull(dst);
                    return; }
                else if(!temp.compare("void")){ size = 0;
                    size = size*state.ArrayVector[i].elementOffset.size();
                    dst<<"addiu"<<" "<<"$"<<reg1<<" , "<<"$"<<"0"<<" , "<<"0x"<<state.toHex(size)<<std::endl;
                    state.ifFull(dst);
                    return; }
            }
        }
        for(int i = state.gloVarVector.size()-1;i>=0;i--){
            if(!state.gloVarVector[i].id.compare(id)){
                dst<<"addiu"<<" "<<"$"<<reg1<<" , "<<"$"<<"0"<<" , "<<"0x"<<state.toHex(state.typeToSize(state.gloVarVector[i].type))<<std::endl;
                state.ifFull(dst);
                return;
            }
        }
        throw std::invalid_argument( "variable used ["+id+"] was not found (previously declared) @size" );
    }

    //for frame size
    void count(CompilerState &state) const override {}
};

class NegOp
    : public ASTNode
{
public:
    node expr;

    NegOp(node _expr)
        : expr(_expr)
    {}

    virtual void print(std::ostream &dst, PrintTransState &state) const override{
        dst<<"-(";
        expr->print(dst,state);
        dst<<")";
    }

    virtual void translate(std::ostream &dst, PrintTransState &state) const override{
        dst<<"-(";
        expr->translate(dst,state);
        dst<<")";
    }

    virtual void compile(std::ostream &dst, CompilerState &state) const override{
        int reg1 = state.getTempReg(1,dst);
        int reg2 = state.getTempReg(0,dst);
        expr->compile(dst,state);
        state.ifLoad(dst,reg2);
        state.registers[reg2]=0;
        int reg3 = state.getTempReg(0,dst);

        dst<<"addiu"<<" "<<"$"<<reg3<<" , "<<"$"<<"0"<<" , "<<"0xFFFF"<<std::endl;
        dst<<"sll"<<" "<<"$"<<reg3<<" , "<<"$"<<reg3<<" , "<<"0xA"<<std::endl;
        dst<<"mult"<<" "<<"$"<<reg2<<" , "<<"$"<<reg3<<std::endl;
        dst<<"mflo"<<" "<<"$"<<reg1<<std::endl;
        state.ifFull(dst);
    }

    //for frame size
    void count(CompilerState &state) const override {
        expr->count(state);
    }
};

class PosOp
    : public ASTNode
{
public:
    node expr;
    PosOp(node _expr)
        : expr(_expr)
    {}

    virtual void print(std::ostream &dst, PrintTransState &state) const override{
        dst<<"+(";
        expr->print(dst,state);
        dst<<")";
    }

    virtual void translate(std::ostream &dst, PrintTransState &state) const override{
        dst<<"+(";
        expr->translate(dst,state);
        dst<<")";
    }

    virtual void compile(std::ostream &dst, CompilerState &state) const override{
        int reg1 = state.getTempReg(1,dst);
        int reg2 = state.getTempReg(0,dst);
        expr->compile(dst,state);
        state.ifLoad(dst,reg2);
        state.registers[reg2]=0;
        int reg3 = state.getTempReg(0,dst);

        dst<<"addiu"<<" "<<reg3<<" , "<<reg3<<" , "<<"0x1"<<std::endl;
        dst<<"mult"<<" "<<reg2<<" , "<<reg3<<std::endl;
        dst<<"mflo"<<" "<<reg1<<std::endl;
        state.ifFull(dst);
    }

    //for frame size
    void count(CompilerState &state) const override {
        expr->count(state);
    }
};

#endif

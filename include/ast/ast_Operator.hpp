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
        int reg2 = state.getTempReg(0);
        left->compile(dst, state);
        int reg3 = state.getTempReg(0);
        right->compile(dst, state);
        state.registers[reg2]=0;
        state.registers[reg3]=0;
        int reg1 = state.getTempReg(1);

        std::string type = getOpcode();
        if(!type.compare("*")){
            dst<<getSignInst()<<" "<<"$"<<reg2<<" , "<<"$"<<reg3<<std::endl;
            dst<<"mflo"<<" "<<"$"<<reg1<<std::endl;
        } else if(!type.compare("/")){
            dst<<getSignInst()<<" "<<"$"<<reg2<<" , "<<"$"<<reg3<<std::endl;
            dst<<"mflo"<<" "<<"$"<<reg1<<std::endl;
        } else if(!type.compare("%")){
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
            int reg1 = state.getTempReg(0);
            int reg2;
            condition->compile(dst,state);
            state.registers[reg1]=0;
            
            reg1 = state.getTempReg(1);
            
            dst<<"beq"<<" "<<"$"<<reg1<<" , "<<"$"<<"0"<<" , "<<"$L"<<(state.labelId)<<std::endl;
            dst<<"nop"<<std::endl;

            reg2 = state.getTempReg(0);
            expression1->compile(dst,state);
            state.registers[reg2]=0;
            dst<<"add"<<" "<<"$"<<reg1<<" , "<<"$"<<reg2<<" , "<<"$"<<"0"<<std::endl;


            dst<<"b"<<" "<<"$L"<<(state.labelId+1)<<std::endl;
            dst<<"nop"<<std::endl;

            dst<<"$L"<<state.label()<<std::endl;

            reg2 = state.getTempReg(0);
            expression2->compile(dst,state);
            state.registers[reg2]=0;
            dst<<"add"<<" "<<"$"<<reg1<<" , "<<"$"<<reg2<<" , "<<"$"<<"0"<<std::endl;

            dst<<"$L"<<state.label()<<std::endl;
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
            int reg1 = state.getTempReg(1);
            int reg2 = state.getTempReg(0);
            expression1->compile(dst,state);
            state.registers[reg2]=0;
            
            reg2 = state.getTempReg(0);
            expression2->compile(dst, state);
            state.registers[reg2]=0;
            dst<<"add"<<" "<<"$"<<reg1<<" , "<<"$"<<reg2<<" , "<<"$"<<"0"<<std::endl;
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
                        throw std::invalid_argument( "argument sizes don't match" );
                    }
                    dst<<"jal"<<" "<<"F"<<state.funcVector[i].labelNo<<std::endl;
                    dst<<"nop"<<std::endl;
                    int reg1 = state.getTempReg(1);
                    if(state.funcVector[i].type.compare("void")){
                        dst<<"sw"<<" "<<"$"<<reg1<<" , "<<"$"<<"2"<<std::endl<<std::endl;
                    }
                    return;
                }
            }
            throw std::invalid_argument( "function not defined" );
        }

        //for frame size
        void count(CompilerState &state) const override {
            int argCount=0;
            int argSpace=0;
            std::string type;
            int size;

            for(unsigned int i=0;i<state.funcVector.size();i++){
                if(!state.funcVector[i].id.compare(id)){
                    argCount=state.funcVector[i].arguments.size();
                    if(state.argCount>argCount){ state.argCount = argCount; }
                    for(int j=0;j<argCount;j++){
                        type=state.funcVector[i].arguments[j];
                        if(!type.compare("char")){ size = 4; /*techincally 1*/ }
                        else if(!type.compare("signed char")){ size = 4; /*techincally 1*/ }
                        else if(!type.compare("unsigned char")){ size = 4; /*techincally 1*/ }
                        else if(!type.compare("short")){ size = 4; /*techincally 2*/ }
                        else if(!type.compare("unsigned short")){ size = 4; /*techincally 2*/ }
                        else if(!type.compare("int")){ size = 4; }
                        else if(!type.compare("unsigned int")){ size = 4; }
                        else if(!type.compare("long")){ size = 8; }
                        else if(!type.compare("unsigned long")){ size = 8; }
                        else if(!type.compare("long long")){ size = 16; }
                        else if(!type.compare("unsigned long long")){ size = 16; }
                        else if(!type.compare("float")){ size = 4; }
                        else if(!type.compare("double")){ size = 8; }
                        else if(!type.compare("long double")){ size = 32; }
                        else if(!type.compare("void")){ size = 0; }
                        else{ throw std::invalid_argument( "type not defined" );}

                        argSpace+=size;
                    }
                    if(argSpace>state.argSpace){
                        state.argSpace=argSpace;
                    }
                    return;
                }
            }
            throw std::invalid_argument( "function not defined" );
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
        int reg1 = state.getTempReg(0);
        std::string temp = id;
        int size=0;
        for(int i=0;i<15;i++){
            if(!temp.compare("char")){ size = 1; }
            else if(!temp.compare("signed char")){ size = 1; }
            else if(!temp.compare("unsigned char")){ size = 1; }
            else if(!temp.compare("short")){ size = 2; }
            else if(!temp.compare("unsigned short")){ size = 2; }
            else if(!temp.compare("int")){ size = 4; }
            else if(!temp.compare("unsigned int")){ size = 4; }
            else if(!temp.compare("long")){ size = 8; }
            else if(!temp.compare("unsigned long")){ size = 8; }
            else if(!temp.compare("long long")){ size = 16; }
            else if(!temp.compare("unsigned long long")){ size = 16; }
            else if(!temp.compare("float")){ size = 4; }
            else if(!temp.compare("double")){ size = 8; }
            else if(!temp.compare("long double")){ size = 32; }
            else if(!temp.compare("void")){ size = 0; }
            else{ throw std::invalid_argument( "type not defined" );}
            dst<<"addi"<<" "<<"$"<<reg1<<" , "<<"$"<<"0"<<" , "<<"0x"<<state.toHex(size)<<std::endl;
            return;
        }
        for(int i = state.varVector.size()-1;i>=0;i--){
            if(!state.varVector[i].id.compare(id)){
                temp = state.varVector[i].type;
                if(!temp.compare("char")){ size = 1; }
                else if(!temp.compare("signed char")){ size = 1; }
                else if(!temp.compare("unsigned char")){ size = 1; }
                else if(!temp.compare("short")){ size = 2; }
                else if(!temp.compare("unsigned short")){ size = 2; }
                else if(!temp.compare("int")){ size = 4; }
                else if(!temp.compare("unsigned int")){ size = 4; }
                else if(!temp.compare("long")){ size = 8; }
                else if(!temp.compare("unsigned long")){ size = 8; }
                else if(!temp.compare("long long")){ size = 16; }
                else if(!temp.compare("unsigned long long")){ size = 16; }
                else if(!temp.compare("float")){ size = 4; }
                else if(!temp.compare("double")){ size = 8; }
                else if(!temp.compare("long double")){ size = 32; }
                else if(!temp.compare("void")){ size = 0; }
                else{ throw std::invalid_argument( "type not defined" );}
                dst<<"addi"<<" "<<"$"<<reg1<<" , "<<"$"<<"0"<<" , "<<"0x"<<state.toHex(size)<<std::endl;
                return;
            }
        }
        throw std::invalid_argument( "variable used was not found (previously declared)" );
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
        int reg1 = state.getTempReg(1);
        int reg2 = state.getTempReg(0);
        expr->compile(dst,state);
        state.registers[reg2]=0;
        int reg3 = state.getTempReg(0);

        dst<<"addi"<<" "<<reg3<<" , "<<reg3<<" , "<<"0xFFFFFFFF"<<std::endl;
        dst<<"mult"<<" "<<reg2<<" , "<<reg3<<std::endl;
        dst<<"mflo"<<" "<<reg1<<std::endl;
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
        int reg1 = state.getTempReg(1);
        int reg2 = state.getTempReg(0);
        expr->compile(dst,state);
        state.registers[reg2]=0;
        int reg3 = state.getTempReg(0);

        dst<<"addi"<<" "<<reg3<<" , "<<reg3<<" , "<<"0x1"<<std::endl;
        dst<<"mult"<<" "<<reg2<<" , "<<reg3<<std::endl;
        dst<<"mflo"<<" "<<reg1<<std::endl;
    }

    //for frame size
    void count(CompilerState &state) const override {
        expr->count(state);
    }
};

#endif

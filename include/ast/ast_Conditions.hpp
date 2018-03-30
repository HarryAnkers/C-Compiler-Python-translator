#ifndef ast_Conditions_hpp
#define ast_Conditions_hpp

#include "ast_ASTNode.hpp"

class LNot : public ASTNode
{
    public:
        node cond;
    
        LNot(node _cond):
        cond(_cond){}

        //print tester
        virtual void print(std::ostream &dst, PrintTransState &state) const override
        {
            dst<<"(!";
            cond->print(dst, state);
            dst<<")";
        }

        //translate
        virtual void translate(std::ostream &dst, PrintTransState &state) const override
        {
            dst<<"(!";
            cond->translate(dst, state);
            dst<<")";
        }

        //compiler 
        virtual void compile(std::ostream &dst, CompilerState &state) const override{
            int reg2 = state.getTempReg(0,dst);
            state.ifLoad(dst,reg2);
            cond->compile(dst, state);
            state.registers[reg2]=0;
            int reg1 = state.getTempReg(1,dst);
            dst<<"sltu"<<" "<<"$"<<reg1<<" , "<<"$"<<reg1<<" , "<<"1"<<std::endl;
            state.ifFull(dst);
        }

        virtual void count(CompilerState &state) const override {
            cond->count(state);
        }
};

class ConditionOp : public ASTNode
{
    public:
        node condA;
        node condB;

        virtual const char *getPyOp() const =0;
        virtual const char *getCOp() const =0;

        ConditionOp(node _condA, node _condB):
            condA(_condA),condB(_condB){}

        //print tester
        virtual void print(std::ostream &dst, PrintTransState &state) const override
        {
            dst<<"(";
            condA->print(dst, state);
            dst<<" ";
            dst<<getCOp();
            dst<<" ";
            condB->print(dst, state);
            dst<<")";
        }

        //translator
        virtual void translate(std::ostream &dst, PrintTransState &state) const override
        {
            dst<<"(";
            condA->translate(dst, state);
            dst<<" ";
            dst<<getPyOp();
            dst<<" ";
            condB->translate(dst, state);
            dst<<")";
        }

        //compiler 
        virtual void compile(std::ostream &dst, CompilerState &state) const override{}

        virtual void count(CompilerState &state) const override {
            condA->count(state);
            condB->count(state);
        }
};

class LEqual : public ConditionOp
{
    public:
        LEqual(node _condA, node _condB):
            ConditionOp(_condA,_condB){}

        virtual const char *getCOp() const override{ return "=="; }
        virtual const char *getPyOp() const override{ return "=="; }

        virtual void compile(std::ostream &dst, CompilerState &state) const override{
            int reg2 = state.getTempReg(0,dst);
            condA->compile(dst, state);
            int reg3 = state.getTempReg(0,dst);
            condB->compile(dst, state);
            state.registers[reg2]=0;
            state.registers[reg3]=0;
            state.ifLoad(dst,reg2);
            state.ifLoad(dst,reg3);
            int reg1 = state.getTempReg(1,dst);
            dst<<"xor"<<" "<<"$"<<reg1<<" , "<<"$"<<reg2<<" , "<<"$"<<reg3<<std::endl;
            dst<<"sltu"<<" "<<"$"<<reg1<<" , "<<"$"<<reg1<<" , "<<"1"<<std::endl;
            state.ifFull(dst);
        }
};

class LAnd : public ConditionOp
{
    public:
        LAnd(node _condA, node _condB):
            ConditionOp(_condA,_condB){}

        virtual const char *getCOp() const override{ return "&&"; }
        virtual const char *getPyOp() const override{ return "and"; }

        virtual void compile(std::ostream &dst, CompilerState &state) const override{
            int reg2 = state.getTempReg(0,dst);
            condA->compile(dst, state);
            int reg3 = state.getTempReg(0,dst);
            condB->compile(dst, state);
            state.registers[reg2]=0;
            state.registers[reg3]=0;
            int reg1 = state.getTempReg(1,dst);
            dst<<"beq"<<" "<<"$"<<reg2<<" , "<<"$"<<"0"<<" , "<<"$L"<<(state.labelId)<<std::endl;
            dst<<"nop"<<std::endl;
            dst<<"beq"<<" "<<"$"<<reg3<<" , "<<"$"<<"0"<<" , "<<"$L"<<(state.labelId)<<std::endl;
            dst<<"nop"<<std::endl;
            //this is true
            dst<<"addiu"<<" "<<"$"<<reg1<<" , "<<"$"<<"0"<<" , "<<"0x1"<<std::endl;
            dst<<"b"<<" "<<"$L"<<(state.labelId+1)<<std::endl;
            dst<<"nop"<<std::endl<<std::endl;
            //this is false
            dst<<"$L"<<(state.label())<<":"<<std::endl;
            dst<<"addiu"<<" "<<"$"<<reg1<<" , "<<"$"<<"0"<<" , "<<"0x0"<<std::endl<<std::endl;
            //this is after both true and false
            dst<<"$L"<<(state.label())<<":"<<std::endl;
            state.ifFull(dst);
        }
};

class LOr : public ConditionOp
{
    public:
        LOr(node _condA, node _condB):
            ConditionOp(_condA,_condB){}

        virtual const char *getCOp() const override{ return "||"; }
        virtual const char *getPyOp() const override{ return "or"; }

        virtual void compile(std::ostream &dst, CompilerState &state) const override{
            int reg2 = state.getTempReg(0,dst);
            condA->compile(dst, state);
            int reg3 = state.getTempReg(0,dst);
            condB->compile(dst, state);
            state.registers[reg2]=0;
            state.registers[reg3]=0;
            int reg1 = state.getTempReg(1,dst);
            dst<<"bne"<<" "<<"$"<<reg2<<" , "<<"$"<<"0"<<" , "<<"$L"<<(state.labelId)<<std::endl;
            dst<<"nop"<<std::endl;
            dst<<"bne"<<" "<<"$"<<reg3<<" , "<<"$"<<"0"<<" , "<<"$L"<<(state.labelId)<<std::endl;
            dst<<"nop"<<std::endl;
            //this is false
            dst<<"addiu"<<" "<<"$"<<reg1<<" , "<<"$"<<"0"<<" , "<<"0x0"<<std::endl;
            dst<<"b"<<" "<<"$L"<<(state.labelId+1)<<std::endl;
            dst<<"nop"<<std::endl<<std::endl;
            //this is true
            dst<<"$L"<<(state.label())<<":"<<std::endl;
            dst<<"addiu"<<" "<<"$"<<reg1<<" , "<<"$"<<"0"<<" , "<<"0x1"<<std::endl<<std::endl;
            //this is after both true and false
            dst<<"$L"<<(state.label())<<":"<<std::endl;
            state.ifFull(dst);
        }
};

class LNotEqual : public ConditionOp
{
    public:
        LNotEqual(node _condA, node _condB):
            ConditionOp(_condA,_condB){}

        virtual const char *getCOp() const override{ return "!="; }
        virtual const char *getPyOp() const override{ return "!="; }

        virtual void compile(std::ostream &dst, CompilerState &state) const override{
            int reg2 = state.getTempReg(0,dst);
            condA->compile(dst, state);
            int reg3 = state.getTempReg(0,dst);
            condB->compile(dst, state);
            state.registers[reg2]=0;
            state.registers[reg3]=0;
            state.ifLoad(dst,reg2);
            state.ifLoad(dst,reg3);
            int reg1 = state.getTempReg(1,dst);
            dst<<"xor"<<" "<<"$"<<reg1<<" , "<<"$"<<reg2<<" , "<<"$"<<reg3<<std::endl;
            dst<<"sltu"<<" "<<"$"<<reg1<<" , "<<"$"<<"0"<<" , "<<"$"<<reg1<<std::endl;
            state.ifFull(dst);
        }
};

class LMore : public ConditionOp
{
    public:
        LMore(node _condA, node _condB):
            ConditionOp(_condA,_condB){}

        virtual const char *getCOp() const override{ return ">"; }
        virtual const char *getPyOp() const override{ return ">"; }

        virtual void compile(std::ostream &dst, CompilerState &state) const override{
            int reg2 = state.getTempReg(0,dst);
            condA->compile(dst, state);
            int reg3 = state.getTempReg(0,dst);
            condB->compile(dst, state);
            state.registers[reg2]=0;
            state.registers[reg3]=0;
            state.ifLoad(dst,reg2);
            state.ifLoad(dst,reg3);
            int reg1 = state.getTempReg(1,dst);
            dst<<"slt"<<" "<<"$"<<reg1<<" , "<<"$"<<reg3<<" , "<<"$"<<reg2<<std::endl;
            state.ifFull(dst);
        }
};

class LLess : public ConditionOp
{
    public:
        LLess(node _condA, node _condB):
            ConditionOp(_condA,_condB){}

        virtual const char *getCOp() const override{ return "<"; }
        virtual const char *getPyOp() const override{ return "<"; }

        virtual void compile(std::ostream &dst, CompilerState &state) const override{
            int reg2 = state.getTempReg(0,dst);
            condA->compile(dst, state);
            int reg3 = state.getTempReg(0,dst);
            condB->compile(dst, state);
            state.registers[reg2]=0;
            state.registers[reg3]=0;
            state.ifLoad(dst,reg2);
            state.ifLoad(dst,reg3);
            int reg1 = state.getTempReg(1,dst);
            dst<<"slt"<<" "<<"$"<<reg1<<" , "<<"$"<<reg3<<" , "<<"$"<<reg2<<std::endl;
            state.ifFull(dst);
        }
};

class LMoreEqual : public ConditionOp
{
    public:
        LMoreEqual(node _condA, node _condB):
            ConditionOp(_condA,_condB){}

        virtual const char *getCOp() const override{ return ">="; }
        virtual const char *getPyOp() const override{ return ">="; }

        virtual void compile(std::ostream &dst, CompilerState &state) const override{
            int reg2 = state.getTempReg(0,dst);
            condA->compile(dst, state);
            int reg3 = state.getTempReg(0,dst);
            condB->compile(dst, state);
            state.registers[reg2]=0;
            state.registers[reg3]=0;
            state.ifLoad(dst,reg2);
            state.ifLoad(dst,reg3);
            int reg1 = state.getTempReg(1,dst);
            dst<<"slt"<<" "<<"$"<<reg1<<" , "<<"$"<<reg2<<" , "<<"$"<<reg3<<std::endl;
            dst<<"xori"<<" "<<"$"<<reg1<<" , "<<"$"<<reg1<<" , "<<"0x1"<<std::endl;
            state.ifFull(dst);
        }
};

class LLessEqual : public ConditionOp
{
    public:
        LLessEqual(node _condA, node _condB):
            ConditionOp(_condA,_condB){}

        virtual const char *getCOp() const override{ return "<="; }
        virtual const char *getPyOp() const override{ return "<="; }

        virtual void compile(std::ostream &dst, CompilerState &state) const override{
            int reg2 = state.getTempReg(0,dst);
            condA->compile(dst, state);
            int reg3 = state.getTempReg(0,dst);
            condB->compile(dst, state);
            state.registers[reg2]=0;
            state.registers[reg3]=0;
            state.ifLoad(dst,reg2);
            state.ifLoad(dst,reg3);
            int reg1 = state.getTempReg(1,dst);
            dst<<"slt"<<" "<<"$"<<reg1<<" , "<<"$"<<reg3<<" , "<<"$"<<reg2<<std::endl;
            dst<<"xori"<<" "<<"$"<<reg1<<" , "<<"$"<<reg1<<" , "<<"0x1"<<std::endl;
            state.ifFull(dst);
        }
};

#endif
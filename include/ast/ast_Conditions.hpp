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
        virtual void compile(std::ostream &dst, CompilerState &state) const override{}
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
};

class LEqual : public ConditionOp
{
    public:
        LEqual(node _condA, node _condB):
            ConditionOp(_condA,_condB){}

        virtual const char *getCOp() const override{ return "=="; }
        virtual const char *getPyOp() const override{ return "=="; }
};

class LAnd : public ConditionOp
{
    public:
        LAnd(node _condA, node _condB):
            ConditionOp(_condA,_condB){}

        virtual const char *getCOp() const override{ return "&&"; }
        virtual const char *getPyOp() const override{ return "and"; }
};

class LOr : public ConditionOp
{
    public:
        LOr(node _condA, node _condB):
            ConditionOp(_condA,_condB){}

        virtual const char *getCOp() const override{ return "||"; }
        virtual const char *getPyOp() const override{ return "or"; }
};

class LNotEqual : public ConditionOp
{
    public:
        LNotEqual(node _condA, node _condB):
            ConditionOp(_condA,_condB){}

        virtual const char *getCOp() const override{ return "!="; }
        virtual const char *getPyOp() const override{ return "!="; }
};

class LMore : public ConditionOp
{
    public:
        LMore(node _condA, node _condB):
            ConditionOp(_condA,_condB){}

        virtual const char *getCOp() const override{ return "<"; }
        virtual const char *getPyOp() const override{ return "<"; }
};

class LLess : public ConditionOp
{
    public:
        LLess(node _condA, node _condB):
            ConditionOp(_condA,_condB){}

        virtual const char *getCOp() const override{ return ">"; }
        virtual const char *getPyOp() const override{ return ">"; }
};

class LMoreEqual : public ConditionOp
{
    public:
        LMoreEqual(node _condA, node _condB):
            ConditionOp(_condA,_condB){}

        virtual const char *getCOp() const override{ return ">="; }
        virtual const char *getPyOp() const override{ return ">="; }
};

class LLessEqual : public ConditionOp
{
    public:
        LLessEqual(node _condA, node _condB):
            ConditionOp(_condA,_condB){}

        virtual const char *getCOp() const override{ return "<="; }
        virtual const char *getPyOp() const override{ return "<="; }
};

#endif
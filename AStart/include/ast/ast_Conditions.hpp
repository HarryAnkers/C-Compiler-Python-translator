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
        virtual void print(std::ostream &dst) const override
        {
            dst<<"(!";
            cond->print(dst);
            dst<<")";
        }

        //translate
        virtual void translate(std::ostream &dst) const override
        {
            dst<<"(!";
            cond->translate(dst);
            dst<<")";
        }

        //compiler 
        virtual void compile(std::ostream &dst, int &indent) const override{}
};

class ConditionOp : public ASTNode
{
    public:
        node condA;
        node condB;
    
        LEqual(node _condA, node _condB):
        condA(_condA), condB(_condB){};

        //print tester
        virtual void print(std::ostream &dst) const override
        {
            dst<<"(";
            left->print(dst);
            dst<<" ";
            dst<<getCOp();
            dst<<" ";
            right->print(dst);
            dst<<")";
        }

        //translator
        virtual void translate(std::ostream &dst) const override
        {
            dst<<"(";
            left->translate(dst);
            dst<<" ";
            dst<<getPyOp();
            dst<<" ";
            right->translate(dst);
            dst<<")";
        }

        //compiler 
        virtual void compile(std::ostream &dst, int &indent) const override{}
};

class LEqual : public ConditionOp
{
    public:
        node condA;
        node condB;
    
        LEqual(node _condA, node _condB):
        condA(_condA), condB(_condB){}

        virtual const char *getCOp() const override{ return "=="; }
        virtual const char *getPyOp() const override{ return "=="; }
};

class LAnd : public ConditionOp
{
    public:
        node condA;
        node condB;
    
        LAnd(node _condA, node _condB):
        condA(_condA), condB(_condB){}

        virtual const char *getCOp() const override{ return "&&"; }
        virtual const char *getPyOp() const override{ return "and"; }
};

class LOr : public ConditionOp
{
    public:
        node condA;
        node condB;
    
        LOr(node _condA, node _condB):
        condA(_condA), condB(_condB){}

        virtual const char *getCOp() const override{ return "||"; }
        virtual const char *getPyOp() const override{ return "or"; }
};

class LNotEqual : public ConditionOp
{
    public:
        node condA;
        node condB;
    
        LNotEqual(node _condA, node _condB):
        condA(_condA), condB(_condB){}

        virtual const char *getCOp() const override{ return "!="; }
        virtual const char *getPyOp() const override{ return "!="; }
};

class LMore : public ConditionOp
{
    public:
        node condA;
        node condB;
    
        LMore(node _condA, node _condB):
        condA(_condA), condB(_condB){}

        virtual const char *getCOp() const override{ return ">"; }
        virtual const char *getPyOp() const override{ return ">"; }
};

class LLess : public ConditionOp
{
    public:
        node condA;
        node condB;
    
        LLess(node _condA, node _condB):
        condA(_condA), condB(_condB){}

        virtual const char *getCOp() const override{ return "<"; }
        virtual const char *getPyOp() const override{ return "<"; }
};

class LMoreEqual : public ConditionOp
{
    public:
        node condA;
        node condB;
    
        LMoreEqual(node _condA, node _condB):
        condA(_condA), condB(_condB){}

        virtual const char *getCOp() const override{ return ">="; }
        virtual const char *getPyOp() const override{ return ">="; }
};

class LLessEqual : public ConditionOp
{
    public:
        node condA;
        node condB;
    
        LLessEqual(node _condA, node _condB):
        condA(_condA), condB(_condB){}

        virtual const char *getCOp() const override{ return "<="; }
        virtual const char *getPyOp() const override{ return "<="; }
};

#endif
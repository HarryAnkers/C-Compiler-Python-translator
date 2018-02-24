
#ifndef ast_Conditions_hpp
#define ast_Conditions_hpp

#include "ast_MainBody.hpp"
#include "ast_Expression.hpp"

class LEqual : public Expression
{
    public:
        ExpressionPtr condA;
        ExpressionPtr condB;
    
        LEqual(ExpressionPtr _condA, ExpressionPtr _condB):
        condA(_condA), condB(_condB){}

        //print tester
        virtual void print(std::ostream &dst) const override
        {
            dst<<"(";
            condA->print(dst);
            dst<<"==";
            condB->print(dst);
            dst<<")";
        }
};

class LAnd : public Expression
{
    public:
        ExpressionPtr condA;
        ExpressionPtr condB;
    
        LAnd(ExpressionPtr _condA, ExpressionPtr _condB):
        condA(_condA), condB(_condB){}

        //print tester
        virtual void print(std::ostream &dst) const override
        {
            dst<<"(";
            condA->print(dst);
            dst<<"&&";
            condB->print(dst);
            dst<<")";
        }
};

class LOr : public Expression
{
    public:
        ExpressionPtr condA;
        ExpressionPtr condB;
    
        LOr(ExpressionPtr _condA, ExpressionPtr _condB):
        condA(_condA), condB(_condB){}

        //print tester
        virtual void print(std::ostream &dst) const override
        {
            dst<<"(";
            condA->print(dst);
            dst<<"||";
            condB->print(dst);
            dst<<")";
        }
};

class LNot : public Expression
{
    public:
        ExpressionPtr cond;
    
        LNot(ExpressionPtr _cond):
        cond(_cond){}

        //print tester
        virtual void print(std::ostream &dst) const override
        {
            dst<<"(!";
            cond->print(dst);
            dst<<")";
        }
};

class LNotEqual : public Expression
{
    public:
        ExpressionPtr condA;
        ExpressionPtr condB;
    
        LNotEqual(ExpressionPtr _condA, ExpressionPtr _condB):
        condA(_condA), condB(_condB){}

        //print tester
        virtual void print(std::ostream &dst) const override
        {
            dst<<"(";
            condA->print(dst);
            dst<<"!|";
            condB->print(dst);
            dst<<")";
        }
};

class LMore : public Expression
{
    public:
        ExpressionPtr condA;
        ExpressionPtr condB;
    
        LMore(ExpressionPtr _condA, ExpressionPtr _condB):
        condA(_condA), condB(_condB){}

        //print tester
        virtual void print(std::ostream &dst) const override
        {
            dst<<"(";
            condA->print(dst);
            dst<<">";
            condB->print(dst);
            dst<<")";
        }
};

class LLess : public Expression
{
    public:
        ExpressionPtr condA;
        ExpressionPtr condB;
    
        LLess(ExpressionPtr _condA, ExpressionPtr _condB):
        condA(_condA), condB(_condB){}

        //print tester
        virtual void print(std::ostream &dst) const override
        {
            dst<<"(";
            condA->print(dst);
            dst<<"<";
            condB->print(dst);
            dst<<")";
        }
};

class LMoreEqual : public Expression
{
    public:
        ExpressionPtr condA;
        ExpressionPtr condB;
    
        LMoreEqual(ExpressionPtr _condA, ExpressionPtr _condB):
        condA(_condA), condB(_condB){}

        //print tester
        virtual void print(std::ostream &dst) const override
        {
            dst<<"(";
            condA->print(dst);
            dst<<">=";
            condB->print(dst);
            dst<<")";
        }
};

class LLessEqual : public Expression
{
    public:
        ExpressionPtr condA;
        ExpressionPtr condB;
    
        LLessEqual(ExpressionPtr _condA, ExpressionPtr _condB):
        condA(_condA), condB(_condB){}

        //print tester
        virtual void print(std::ostream &dst) const override
        {
            dst<<"(";
            condA->print(dst);
            dst<<"<=";
            condB->print(dst);
            dst<<")";
        }
};

#endif
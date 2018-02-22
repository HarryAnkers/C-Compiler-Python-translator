#ifndef ast_Statement_hpp
#define ast_Statement_hpp

#include "ast_MainBody.hpp"
#include "ast_expression.hpp"

class Statement : public MainBody
{
    public:
        //print tester
        virtual void print(std::ostream &dst) const =0;

        //translator 
        virtual void translate(std::ostream &dst) const =0;
};

class ReturnStatement : public Statement
{
    protected:
        ExpressionPtr expression;

        ReturnStatement(ExpressionPtr _expression):
        expression(_expression){}
    public:

        //print tester
        virtual void print(std::ostream &dst) const override
        {
            dst<<"return "<<std::endl;
            expression->print(dst);
        }

        //translator 
        virtual void translate(std::ostream &dst) const =0;
};

class AssignStatement : public Statement
{
    protected:
        string id;
        ExpressionPtr expression;

        AssignStatement(string _id, CompileExpressionPtrrPtr _expression):
        id(_id), expression(_expression){}
    public:
        //print tester
        virtual void print(std::ostream &dst) const override
        {
            dst<<"return "<<std::endl;
            expression->print(dst);
        }

        //translator 
        virtual void translate(std::ostream &dst) const =0;
};

#endif

#ifndef ast_Statement_hpp
#define ast_Statement_hpp

#include "ast_MainBody.hpp"

class Statement : public MainBody
{
    protected:
        CompilerPtr expression;

        Statement(CompilerPtr _expression):
        expression(_expression){}
    public:
        CompilerPtr getExpression(){return expression;}

        //print tester
        virtual void print(std::ostream &dst) const =0;

        //translator 
        virtual void translate(std::ostream &dst) const =0;
};

class ReturnStatement : public Statement
{
    protected:
        ReturnStatement(CompilerPtr _expression):
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
        ReturnStatement(CompilerPtr _expression):
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

#endif

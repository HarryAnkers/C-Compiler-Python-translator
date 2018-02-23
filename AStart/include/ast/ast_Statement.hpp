#ifndef ast_Statement_hpp
#define ast_Statement_hpp

#include "ast_MainBody.hpp"
#include "ast_expression.hpp"

class ReturnStatement : public MainBody
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
        virtual void translate(std::ostream &dst) const override{};
};

class AssignStatement : public MainBody
{
    protected:
        std::string id;
        ExpressionPtr expression;

        AssignStatement(std::string _id, ExpressionPtr _expression):
        id(_id), expression(_expression){}
    public:
        //print tester
        virtual void print(std::ostream &dst) const override
        {
            dst<<"return "<<std::endl;
            expression->print(dst);
        }

        //translator 
        virtual void translate(std::ostream &dst) const override{};
};

class DeclareStatement : public MainBody
{
    protected:
        std::string type;
        std::string id;
        ExpressionPtr expression;

        DeclareStatement(std::string _type, std::string _id, ExpressionPtr _expression):
        type(_type), id(_id), expression(_expression){}
        DeclareStatement(std::string _type, std::string _id):
        type(_type), id(_id){}
    public:
        //print tester
        virtual void print(std::ostream &dst) const override
        {
            dst<<id<<"=";
            expression->print(dst);
        }

        //translator 
        virtual void translate(std::ostream &dst) const override{};
};

#endif

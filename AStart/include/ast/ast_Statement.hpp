#ifndef ast_Statement_hpp
#define ast_Statement_hpp

#include "ast_MainBody.hpp"
#include "ast_expression.hpp"

class ReturnStatement : public MainBody
{
    public:
        ExpressionPtr expression;

        ReturnStatement(ExpressionPtr _expression):
        expression(_expression){}

        //print tester
        virtual void print(std::ostream &dst) const override
        {
            dst<<"return ";
            expression->print(dst);
            dst<<";"<<std::endl;
        }

        //translator 
        virtual void translate(std::ostream &dst) const override{};
};

class AssignStatement : public MainBody
{
    public:
        std::string id;
        ExpressionPtr expression;

        AssignStatement(std::string &_id, ExpressionPtr _expression):
        id(_id), expression(_expression){}

        //print tester
        virtual void print(std::ostream &dst) const override
        {
            dst<<id<<"=";
            expression->print(dst);
            dst<<";"<<std::endl;
        }

        //translator 
        virtual void translate(std::ostream &dst) const override{};
};

class DeclareStatement : public MainBody
{
    public:
        std::string type;
        std::string id;
        ExpressionPtr expression;

        DeclareStatement(std::string &_type, std::string &_id, ExpressionPtr _expression):
        type(_type), id(_id), expression(_expression){}
        DeclareStatement(std::string &_type, std::string &_id):
        type(_type), id(_id), expression(NULL){}

        //print tester
        virtual void print(std::ostream &dst) const override
        {
            dst<<type<<" "<<id;
            if(expression!=NULL){
                dst<<"=";
                expression->print(dst);
            }
            dst<<";"<<std::endl;
        }

        //translator 
        virtual void translate(std::ostream &dst) const override{};
};

class FunctionStatement : public MainBody
{
    public:
        std::string id;

        FunctionStatement(std::string &_id):
        id(_id){}

        //print tester
        virtual void print(std::ostream &dst) const override
        {
            dst<<id<<"(";

            dst<<id<<");";
        }

        //translator 
        virtual void translate(std::ostream &dst) const override{};
};

#endif

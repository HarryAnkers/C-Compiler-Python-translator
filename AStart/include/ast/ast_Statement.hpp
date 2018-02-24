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
        virtual void print(std::ostream &dst, int &indent) const override
        {
            for(int i=indent;i!=0;i--){
                dst<<"\t";
            }
            dst<<"return ";
            expression->print(dst);
            dst<<";"<<std::endl;
        }

        //translator 
        virtual void translate(std::ostream &dst, int &indent) const override{
            for(int i=indent;i!=0;i--){
                dst<<"\t";
            }
            dst<<"return ";
            expression->print(dst);
            dst<<std::endl;
        };
};

class AssignStatement : public MainBody
{
    public:
        std::string id;
        ExpressionPtr expression;

        AssignStatement(std::string &_id, ExpressionPtr _expression):
        id(_id), expression(_expression){}

        //print tester
        virtual void print(std::ostream &dst, int &indent) const override
        {
            for(int i=indent;i!=0;i--){
                dst<<"\t";
            }
            dst<<id<<"=";
            expression->print(dst);
            dst<<";"<<std::endl;
        }

        //translator 
        virtual void translate(std::ostream &dst, int &indent) const override{
            for(int i=indent;i!=0;i--){
                dst<<"\t";
            }
            dst<<id<<"=";
            expression->print(dst);
            dst<<std::endl;
        };
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
        virtual void print(std::ostream &dst, int &indent) const override
        {
            for(int i=indent;i!=0;i--){
                dst<<"\t";
            }
            dst<<type<<" "<<id;
            if(expression!=NULL){
                dst<<"=";
                expression->print(dst);
            }
            dst<<";"<<std::endl;
        }

        //translator 
        virtual void translate(std::ostream &dst, int &indent) const override{
            for(int i=indent;i!=0;i--){
                dst<<"\t";
            }
            dst<<id;
            if(expression!=NULL){
                dst<<"=";
                expression->print(dst);
                dst<<std::endl;
            } else { 
                dst<<"=0"<<std::endl; 
            }
        };
};

class FunctionStatement : public MainBody
{
    public:
        std::string id;
        CompilerPtr arguments;

        FunctionStatement(std::string &_id, CompilerPtr _arguments):
        id(_id), arguments(_arguments){}

        //print tester
        virtual void print(std::ostream &dst, int &indent) const override
        {
            for(int i=indent;i!=0;i--){
                dst<<"\t";
            }
            dst<<id<<"(";
            arguments->print(dst,indent);
            dst<<");";
        }

        //translator 
        virtual void translate(std::ostream &dst, int &indent) const override{
            for(int i=indent;i!=0;i--){
                dst<<"\t";
            }
            dst<<id<<"(";
            arguments->print(dst,indent);
            dst<<")";
        }
};

class If_Statement : public MainBody
{
    public:
        ExpressionPtr condition;
        CompilerPtr body;
    
        If_Statement(ExpressionPtr _condition, CompilerPtr _body):
        condition(_condition), body(_body){}

        //print tester
        virtual void print(std::ostream &dst, int &indent) const override
        {
            for(int i=indent;i!=0;i--){
                dst<<"\t";
            }
            dst<<"if ";
            condition->print(dst);
            dst<<" {"<<std::endl;
            indent++;
            body->print(dst,indent);
            indent--;
            for(int i=indent;i!=0;i--){
                dst<<"\t";
            }
            dst<<"}"<<std::endl;
        }

        //translator 
        virtual void translate(std::ostream &dst, int &indent) const override{
            for(int i=indent;i!=0;i--){
                dst<<"\t";
            }
            dst<<"if ";
            condition->print(dst);
            dst<<" {"<<std::endl;
            indent++;
            body->translate(dst,indent);
            indent--;
            for(int i=indent;i!=0;i--){
                dst<<"\t";
            }
            dst<<"}"<<std::endl;
        }
};

class ElIf_Statement : public MainBody
{
    public:
        ExpressionPtr condition;
        CompilerPtr body;
    
        ElIf_Statement(ExpressionPtr _condition, CompilerPtr _body):
        condition(_condition), body(_body){}

        //print tester
        virtual void print(std::ostream &dst, int &indent) const override
        {
            for(int i=indent;i!=0;i--){
                dst<<"\t";
            }
            dst<<"else if (";
            condition->print(dst);
            dst<<") {"<<std::endl;
            indent++;
            body->print(dst,indent);
            indent--;
            for(int i=indent;i!=0;i--){
                dst<<"\t";
            }
            dst<<"}"<<std::endl;
        }

        //translator 
        virtual void translate(std::ostream &dst, int &indent) const override{
            for(int i=indent;i!=0;i--){
                dst<<"\t";
            }
            dst<<"elif(";
            condition->print(dst);
            dst<<") {"<<std::endl;
            indent++;
            body->translate(dst,indent);
            indent--;
            for(int i=indent;i!=0;i--){
                dst<<"\t";
            }
            dst<<"}"<<std::endl;
        }
};

class Else_Statement : public MainBody
{
    public:
        CompilerPtr body;
    
        Else_Statement(CompilerPtr _body):
        body(_body){}

        //print tester
        virtual void print(std::ostream &dst, int &indent) const override
        {
            for(int i=indent;i!=0;i--){
                dst<<"\t";
            }
            dst<<"else {"<<std::endl;
            indent++;
            body->print(dst,indent);
            indent--;
            for(int i=indent;i!=0;i--){
                dst<<"\t";
            }
            dst<<"}"<<std::endl;
        }

        //translator 
        virtual void translate(std::ostream &dst, int &indent) const override{
            for(int i=indent;i!=0;i--){
                dst<<"\t";
            }
            dst<<"else {"<<std::endl;
            indent++;
            body->translate(dst,indent);
            indent--;
            for(int i=indent;i!=0;i--){
                dst<<"\t";
            }
            dst<<"}"<<std::endl;
        }
};

class While_Statement : public MainBody
{
    public:
        ExpressionPtr condition;
        CompilerPtr body;
    
        While_Statement(ExpressionPtr _condition, CompilerPtr _body):
        condition(_condition), body(_body){}

        //print tester
        virtual void print(std::ostream &dst, int &indent) const override
        {
            for(int i=indent;i!=0;i--){
                dst<<"\t";
            }
            dst<<"While ";
            condition->print(dst);
            dst<<" {"<<std::endl;
            indent++;
            body->print(dst,indent);
            indent--;
            for(int i=indent;i!=0;i--){
                dst<<"\t";
            }
            dst<<"}"<<std::endl;
        }

        //translator 
        virtual void translate(std::ostream &dst, int &indent) const override{
            for(int i=indent;i!=0;i--){
                dst<<"\t";
            }
            dst<<"While ";
            condition->print(dst);
            dst<<" {"<<std::endl;
            indent++;
            body->translate(dst,indent);
            indent--;
            for(int i=indent;i!=0;i--){
                dst<<"\t";
            }
            dst<<"}"<<std::endl;
        }
};

#endif

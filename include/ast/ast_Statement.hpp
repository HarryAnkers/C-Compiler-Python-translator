#ifndef ast_Statement_hpp
#define ast_Statement_hpp

#include "ast_ASTNode.hpp"

class Statement : public ASTNode
{
    public:
        std::string statementType;
};

class ReturnStatement : public Statement
{
    public:
        node expression;

        ReturnStatement(node _expression):
        expression(_expression){}

        statementType="return";

        //print tester
        virtual void print(std::ostream &dst, int &indent) const override
        {
            for(int i=indent;i!=0;i--){
                dst<<"\t";
            }
            dst<<"return ";
            expression->print(dst,indent);
            dst<<";"<<std::endl;
        }

        //translator 
        virtual void translate(std::ostream &dst, int &indent) const override{
            for(int i=indent;i!=0;i--){
                dst<<"\t";
            }
            dst<<"return ";
            expression->translate(dst,indent);
            dst<<std::endl;
        }

        //compiler 
        virtual void compile(std::ostream &dst, CompilerState &state) const override{}
};

class AssignStatement : public Statement
{
    public:
        std::string id;
        node expression;

        AssignStatement(std::string &_id, node _expression):
        id(_id), expression(_expression){}

        statementType="assign";

        //print tester
        virtual void print(std::ostream &dst, int &indent) const override
        {
            for(int i=indent;i!=0;i--){
                dst<<"\t";
            }
            dst<<id<<"=";
            expression->print(dst,indent);
            dst<<";"<<std::endl;
        }

        //translator 
        virtual void translate(std::ostream &dst, int &indent) const override{
            for(int i=indent;i!=0;i--){
                dst<<"\t";
            }
            dst<<id<<"=";
            expression->translate(dst,indent);
            dst<<std::endl;
        }

        //compiler 
        virtual void compile(std::ostream &dst, CompilerState &state) const override{}
};

class DeclareStatement : public Statement
{
    public:
        std::string type;
        std::string id;
        node expression;

        DeclareStatement(std::string &_type, std::string &_id, node _expression):
        type(_type), id(_id), expression(_expression){}
        DeclareStatement(std::string &_type, std::string &_id):
        type(_type), id(_id), expression(NULL){}

        statementType="declare";

        //print tester
        virtual void print(std::ostream &dst, int &indent) const override
        {
            for(int i=indent;i!=0;i--){
                dst<<"\t";
            }
            dst<<type<<" "<<id;
            if(expression!=NULL){
                dst<<"=";
                expression->print(dst,indent);
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
                expression->translate(dst,indent);
                dst<<std::endl;
            } else { 
                dst<<"=0"<<std::endl; 
            }
        }

        //compiler 
        virtual void compile(std::ostream &dst, CompilerState &state) const override{}
};

class GlobalDeclareStatement : public Statement
{
    public:
        std::string type;
        std::string id;
        node expression;

        GlobalDeclareStatement(std::string &_type, std::string &_id, node _expression):
        type(_type), id(_id), expression(_expression){ globalVar.push_back(id); }
        GlobalDeclareStatement(std::string &_type, std::string &_id):
        type(_type), id(_id), expression(NULL){ globalVar.push_back(id); }

        statementType="global_declare";

        //print tester
        virtual void print(std::ostream &dst, int &indent) const override
        {
            for(int i=indent;i!=0;i--){
                dst<<"\t";
            }
            dst<<type<<" "<<id;
            if(expression!=NULL){
                dst<<"=";
                expression->print(dst,indent);
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
                expression->translate(dst,indent);
                dst<<std::endl;
            } else { 
                dst<<"=0"<<std::endl; 
            }
        }

        //compiler 
        virtual void compile(std::ostream &dst, CompilerState &state) const override{}
};

class FunctionStatement : public Statement
{
    public:
        std::string id;
        node arguments;

        FunctionStatement(std::string &_id, node _arguments):
        id(_id), arguments(_arguments){}

        statementType="function";

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
            arguments->translate(dst,indent);
            dst<<");";
        }

        //compiler 
        virtual void compile(std::ostream &dst, CompilerState &state) const override{}
};

class If_Statement : public Statement
{
    public:
        node condition;
        node body;
    
        If_Statement(node _condition, node _body):
        condition(_condition), body(_body){}

        statementType="if";

        //print tester
        virtual void print(std::ostream &dst, int &indent) const override
        {
            for(int i=indent;i!=0;i--){
                dst<<"\t";
            }
            dst<<"if ";
            condition->print(dst,indent);
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
            condition->translate(dst,indent);
            dst<<" :"<<std::endl;
            indent++;
            body->translate(dst,indent);
            indent--;
        }

        //compiler 
        virtual void compile(std::ostream &dst, CompilerState &state) const override{}
};

class ElIf_Statement : public Statement
{
    public:
        node condition;
        node body;
    
        ElIf_Statement(node _condition, node _body):
        condition(_condition), body(_body){}

        statementType="elif";

        //print tester
        virtual void print(std::ostream &dst, int &indent) const override
        {
            for(int i=indent;i!=0;i--){
                dst<<"\t";
            }
            dst<<"else if (";
            condition->print(dst,indent);
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
            condition->translate(dst,indent);
            dst<<") :"<<std::endl;
            indent++;
            body->translate(dst,indent);
            indent--;
        }

        //compiler 
        virtual void compile(std::ostream &dst, CompilerState &state) const override{}
};

class Else_Statement : public Statement
{
    public:
        node body;
    
        Else_Statement(node _body):
        body(_body){}

        statementType="else";

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
            dst<<"else :"<<std::endl;
            indent++;
            body->translate(dst,indent);
            indent--;
        }

        //compiler 
        virtual void compile(std::ostream &dst, CompilerState &state) const override{}
};

class While_Statement : public Statement
{
    public:
        node condition;
        node body;
    
        While_Statement(node _condition, node _body):
        condition(_condition), body(_body){}

        statementType="while";

        //print tester
        virtual void print(std::ostream &dst, int &indent) const override
        {
            for(int i=indent;i!=0;i--){
                dst<<"\t";
            }
            dst<<"While ";
            condition->print(dst,indent);
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
            condition->translate(dst,indent);
            dst<<" :"<<std::endl;
            indent++;
            body->translate(dst,indent);
            indent--;
        }

        //compiler 
        virtual void compile(std::ostream &dst, CompilerState &state) const override{}
};

class Do_While_Statement : public Statement
{
    public:
        node condition;
        node body;
    
        Do_While_Statement(node _condition, node _body):
        condition(_condition), body(_body){}

        statementType="do_while";

        //print tester
        virtual void print(std::ostream &dst, int &indent) const override
        {
            for(int i=indent;i!=0;i--){
                dst<<"\t";
            }
            dst<<"do";
            dst<<" {"<<std::endl;
            indent++;
            body->print(dst,indent);
            indent--;
            for(int i=indent;i!=0;i--){
                dst<<"\t";
            }
            dst<<"} while ";
            condition->print(dst,indent);
            dst<<std::endl;
        }

        //translator 
        virtual void translate(std::ostream &dst, int &indent) const override{
            /*for(int i=indent;i!=0;i--){
                dst<<"\t";
            }
            dst<<"While ";
            condition->translate(dst,indent);
            dst<<" :"<<std::endl;
            indent++;
            body->translate(dst,indent);
            indent--;*/
            //not sure how to do this
        }

        //compiler 
        virtual void compile(std::ostream &dst, CompilerState &state) const override{}
};

#endif

#ifndef ast_Statement_hpp
#define ast_Statement_hpp

#include "ast_ASTNode.hpp"

class Statement : public ASTNode{
    virtual std::string getStateType() const {return "";};
    virtual std::string getVarType() const {return "";};

    void count(int &cnt) const {
        std::string type = getStateType();
        if(!type.compare("declare")){
            type = getVarType();
            if(!type.compare("int")){
                cnt++;
            } else if(!type.compare("long")){
                cnt=cnt+2;
            }
        }
    }
};

class ReturnStatement : public Statement
{
    public:
        node expression;

        ReturnStatement(node _expression):
        expression(_expression){}

        virtual std::string getStateType() const override { return "return"; }

        //print tester
        virtual void print(std::ostream &dst, PrintTransState &state) const override
        {
            for(int i=state.indent;i!=0;i--){
                dst<<"\t";
            }
            dst<<"return ";
            expression->print(dst, state);
            dst<<";"<<std::endl;
        }

        //translator 
        virtual void translate(std::ostream &dst, PrintTransState &state) const override{
            for(int i=state.indent;i!=0;i--){
                dst<<"\t";
            }
            dst<<"return ";
            expression->translate(dst, state);
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

        virtual std::string getStateType() const override { return "assign"; }

        //print tester
        virtual void print(std::ostream &dst, PrintTransState &state) const override
        {
            for(int i=state.indent;i!=0;i--){
                dst<<"\t";
            }
            dst<<id<<"=";
            expression->print(dst, state);
            dst<<";"<<std::endl;
        }

        //translator 
        virtual void translate(std::ostream &dst, PrintTransState &state) const override{
            for(int i=state.indent;i!=0;i--){
                dst<<"\t";
            }
            dst<<id<<"=";
            expression->translate(dst, state);
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

        virtual std::string getStateType() const override { return "declare"; }
        virtual std::string getVarType() const override { return type; }

        //print tester
        virtual void print(std::ostream &dst, PrintTransState &state) const override
        {
            for(int i=state.indent;i!=0;i--){
                dst<<"\t";
            }
            dst<<type<<" "<<id;
            if(expression!=NULL){
                dst<<"=";
                expression->print(dst, state);
            }
            dst<<";"<<std::endl;
        }

        //translator 
        virtual void translate(std::ostream &dst, PrintTransState &state) const override{
            for(int i=state.indent;i!=0;i--){
                dst<<"\t";
            }
            dst<<id;
            if(expression!=NULL){
                dst<<"=";
                expression->translate(dst, state);
                dst<<std::endl;
            } else { 
                dst<<"=0"<<std::endl; 
            }
        }

        //compiler 
        virtual void compile(std::ostream &dst, CompilerState &state) const override{
            state.varVector.push_back(VariableBind(id, type, state.currentScope));
        }
};

class GlobalDeclareStatement : public Statement
{
    public:
        std::string type;
        std::string id;
        node expression;

        GlobalDeclareStatement(std::string &_type, std::string &_id, node _expression):
        type(_type), id(_id), expression(_expression){}
        GlobalDeclareStatement(std::string &_type, std::string &_id):
        type(_type), id(_id), expression(NULL){}

        virtual std::string getStateType() const override { return "global_declare"; }

        //print tester
        virtual void print(std::ostream &dst, PrintTransState &state) const override
        {
            for(int i=state.indent;i!=0;i--){
                dst<<"\t";
            }
            dst<<type<<" "<<id;
            if(expression!=NULL){
                dst<<"=";
                expression->print(dst, state);
            }
            dst<<";"<<std::endl;
        }

        //translator 
        virtual void translate(std::ostream &dst, PrintTransState &state) const override{
            state.gloVariables.push_back(id);
            for(int i=state.indent;i!=0;i--){
                dst<<"\t";
            }
            dst<<id;
            if(expression!=NULL){
                dst<<"=";
                expression->translate(dst, state);
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

        virtual std::string getStateType() const override { return "function"; }

        //print tester
        virtual void print(std::ostream &dst, PrintTransState &state) const override
        {
            for(int i=state.indent;i!=0;i--){
                dst<<"\t";
            }
            dst<<id<<"(";
            arguments->print(dst, state);
            dst<<");";
        }

        //translator 
        virtual void translate(std::ostream &dst, PrintTransState &state) const override{
            for(int i=state.indent;i!=0;i--){
                dst<<"\t";
            }
            dst<<id<<"(";
            arguments->translate(dst, state);
            dst<<");";
        }

        //compiler 
        virtual void compile(std::ostream &dst, CompilerState &state) const override{}
};

class NewScope : public Statement
{
    public:
        node body;

        NewScope(node _body): 
            body(_body){}

        virtual std::string getStateType() const override { return "new_scope"; }

        //print tester
        virtual void print(std::ostream &dst, PrintTransState &state) const override
        {
            for(int i=state.indent;i!=0;i--){
                dst<<"\t";
            }
            dst<<"{"<<std::endl;
            state.indent++;
            body->print(dst, state);
            state.indent--;
            for(int i=state.indent;i!=0;i--){
                dst<<"\t";
            }
            dst<<"}"<<std::endl;
        }

        //translator 
        virtual void translate(std::ostream &dst, PrintTransState &state) const override{
            body->translate(dst, state);
        }

        //compiler 
        virtual void compile(std::ostream &dst, CompilerState &state) const override{
            state.currentScope++;
            body->compile(dst, state);
            state.popScope();
        }
};

class If_Statement : public Statement
{
    public:
        node condition;
        node body;
    
        If_Statement(node _condition, node _body):
        condition(_condition), body(_body){}

        virtual std::string getStateType() const override { return "if"; }

        //print tester
        virtual void print(std::ostream &dst, PrintTransState &state) const override
        {
            for(int i=state.indent;i!=0;i--){
                dst<<"\t";
            }
            dst<<"if ";
            condition->print(dst, state);
            dst<<" {"<<std::endl;
            state.indent++;
            body->print(dst, state);
            state.indent--;
            for(int i=state.indent;i!=0;i--){
                dst<<"\t";
            }
            dst<<"}"<<std::endl;
        }

        //translator 
        virtual void translate(std::ostream &dst, PrintTransState &state) const override{
            for(int i=state.indent;i!=0;i--){
                dst<<"\t";
            }
            dst<<"if ";
            condition->translate(dst, state);
            dst<<" :"<<std::endl;
            state.indent++;
            body->translate(dst, state);
            state.indent--;
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

        virtual std::string getStateType() const override { return "elif"; }

        //print tester
        virtual void print(std::ostream &dst, PrintTransState &state) const override
        {
            for(int i=state.indent;i!=0;i--){
                dst<<"\t";
            }
            dst<<"else if (";
            condition->print(dst, state);
            dst<<") {"<<std::endl;
            state.indent++;
            body->print(dst, state);
            state.indent--;
            for(int i=state.indent;i!=0;i--){
                dst<<"\t";
            }
            dst<<"}"<<std::endl;
        }

        //translator 
        virtual void translate(std::ostream &dst, PrintTransState &state) const override{
            for(int i=state.indent;i!=0;i--){
                dst<<"\t";
            }
            dst<<"elif(";
            condition->translate(dst, state);
            dst<<") :"<<std::endl;
            state.indent++;
            body->translate(dst, state);
            state.indent--;
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

        virtual std::string getStateType() const override { return "else"; }

        //print tester
        virtual void print(std::ostream &dst, PrintTransState &state) const override
        {
            for(int i=state.indent;i!=0;i--){
                dst<<"\t";
            }
            dst<<"else {"<<std::endl;
            state.indent++;
            body->print(dst, state);
            state.indent--;
            for(int i=state.indent;i!=0;i--){
                dst<<"\t";
            }
            dst<<"}"<<std::endl;
        }

        //translator 
        virtual void translate(std::ostream &dst, PrintTransState &state) const override{
            for(int i=state.indent;i!=0;i--){
                dst<<"\t";
            }
            dst<<"else :"<<std::endl;
            state.indent++;
            body->translate(dst, state);
            state.indent--;
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

        virtual std::string getStateType() const override { return "while"; }

        //print tester
        virtual void print(std::ostream &dst, PrintTransState &state) const override
        {
            for(int i=state.indent;i!=0;i--){
                dst<<"\t";
            }
            dst<<"While ";
            condition->print(dst, state);
            dst<<" {"<<std::endl;
            state.indent++;
            body->print(dst, state);
            state.indent--;
            for(int i=state.indent;i!=0;i--){
                dst<<"\t";
            }
            dst<<"}"<<std::endl;
        }

        //translator 
        virtual void translate(std::ostream &dst, PrintTransState &state) const override{
            for(int i=state.indent;i!=0;i--){
                dst<<"\t";
            }
            dst<<"While ";
            condition->translate(dst, state);
            dst<<" :"<<std::endl;
            state.indent++;
            body->translate(dst, state);
            state.indent--;
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

        virtual std::string getStateType() const override { return "do_while"; }

        //print tester
        virtual void print(std::ostream &dst, PrintTransState &state) const override
        {
            for(int i=state.indent;i!=0;i--){
                dst<<"\t";
            }
            dst<<"do";
            dst<<" {"<<std::endl;
            state.indent++;
            body->print(dst, state);
            state.indent--;
            for(int i=state.indent;i!=0;i--){
                dst<<"\t";
            }
            dst<<"} while ";
            condition->print(dst, state);
            dst<<std::endl;
        }

        //translator 
        virtual void translate(std::ostream &dst, PrintTransState &state) const override{
            /*for(int i=state.indent;i!=0;i--){
                dst<<"\t";
            }
            dst<<"While ";
            condition->translate(dst, state);
            dst<<" :"<<std::endl;
            state.indent++;
            body->translate(dst, state);
            state.indent--;*/
            //not sure how to do this
        }

        //compiler 
        virtual void compile(std::ostream &dst, CompilerState &state) const override{}
};

#endif

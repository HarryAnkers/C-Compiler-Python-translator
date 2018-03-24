#ifndef ast_Statement_hpp
#define ast_Statement_hpp

#include "ast_ASTNode.hpp"

class ReturnStatement : public ASTNode
{
    public:
        node expression;

        ReturnStatement(node _expression):
        expression(_expression){}

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
        virtual void compile(std::ostream &dst, CompilerState &state) const override{
            int reg1 = state.getTempReg(0);
            expression->compile(dst,state);
            dst<<"add"<<" "<<"$"<<"2"<<" , "<<"$"<<reg1<<" , "<<"$"<<"0"<<std::endl;
            state.registers[reg1]=0;
            dst<<"b"<<" "<<"$E"<<state.returnId<<std::endl;
        }

        //for frame size
        void count(CompilerState &state) const override {
            expression->count(state);
        }
};

class ExprStatement : public ASTNode
{
    public:
        node expression;

        ExprStatement(node _expression):
        expression(_expression){}

        //print tester
        virtual void print(std::ostream &dst, PrintTransState &state) const override
        {
            for(int i=state.indent;i!=0;i--){
                dst<<"\t";
            }
            expression->print(dst, state);
            dst<<";"<<std::endl;
        }

        //translator 
        virtual void translate(std::ostream &dst, PrintTransState &state) const override{
            for(int i=state.indent;i!=0;i--){
                dst<<"\t";
            }
            expression->translate(dst, state);
            dst<<std::endl;
        }

        //compiler 
        virtual void compile(std::ostream &dst, CompilerState &state) const override{
            int reg1 = state.getTempReg(0);
            expression->compile(dst,state);
            state.registers[reg1]=0;
        }

        //for frame size
        void count(CompilerState &state) const override {
            expression->count(state);
        }
};

class DeclareStatement : public ASTNode
{
    public:
        std::string type;
        std::string id;
        node expression;

        DeclareStatement(std::string &_type, std::string &_id, node _expression):
        type(_type), id(_id), expression(_expression){}
        DeclareStatement(std::string &_type, std::string &_id):
        type(_type), id(_id), expression(NULL){}

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
            int offset=state.offset();
            state.varVector.push_back(VariableBind(id, type, state.currentScope,offset));
            if(expression!=NULL){
                int reg1 = state.getTempReg(0);
                expression->compile(dst,state);
                dst<<"sw "<<"$"<<reg1<<" , "<<offset<<"($fp)"<<std::endl;
                state.registers[reg1]=0;
            } else {
                int reg1 = state.getTempReg(1);
                dst<<"addi"<<" "<<"$"<<reg1<<" , "<<"$"<<"0"<<" , "<<"0x0"<<std::endl;
	            dst<<"sw "<<"$"<<reg1<<" , "<<offset<<"($fp)"<<std::endl;
                state.registers[reg1]=0;
            }
        }

        //for frame size
        void count(CompilerState &state) const override {
            if(expression!=NULL){
                expression->count(state);
            }
            int size;

            if(!type.compare("char")){ size = 4; /*techincally 1*/ }
            else if(!type.compare("signed char")){ size = 4; /*techincally 1*/ }
            else if(!type.compare("unsigned char")){ size = 4; /*techincally 1*/ }
            else if(!type.compare("short")){ size = 4; /*techincally 2*/ }
            else if(!type.compare("unsigned short")){ size = 4; /*techincally 2*/ }
            else if(!type.compare("int")){ size = 4; }
            else if(!type.compare("unsigned int")){ size = 4; }
            else if(!type.compare("long")){ size = 8; }
            else if(!type.compare("unsigned long")){ size = 8; }
            else if(!type.compare("long long")){ size = 16; }
            else if(!type.compare("unsigned long long")){ size = 16; }
            else if(!type.compare("float")){ size = 4; }
            else if(!type.compare("double")){ size = 8; }
            else if(!type.compare("long double")){ size = 32; }
            else if(!type.compare("void")){ size = 0; }
            else{ throw std::invalid_argument( "type not defined" );}

            state.varCount=state.varCount+size;
        }
};

class GlobalDeclareStatement : public ASTNode
{
    public:
        std::string type;
        std::string id;
        node expression;

        GlobalDeclareStatement(std::string &_type, std::string &_id, node _expression):
        type(_type), id(_id), expression(_expression){}
        GlobalDeclareStatement(std::string &_type, std::string &_id):
        type(_type), id(_id), expression(NULL){}

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
        virtual void compile(std::ostream &dst, CompilerState &state) const override{
            int offset=state.offset();
            state.varVector.push_back(VariableBind(id, type, state.currentScope,offset));
            if(expression!=NULL){
                int reg1 = state.getTempReg(0);
                expression->compile(dst,state);
                dst<<"sw "<<"$"<<reg1<<" , "<<offset<<"($fp)"<<std::endl;
                state.registers[reg1]=0;
            } else {
                int reg1 = state.getTempReg(1);
                dst<<"addi"<<" "<<"$"<<reg1<<" , "<<"$"<<"0"<<" , "<<"0x0"<<std::endl;
	            dst<<"sw "<<"$"<<reg1<<" , "<<offset<<"($fp)"<<std::endl;
                state.registers[reg1]=0;
            }
            //not sure if correct
        }

        virtual void count(CompilerState &state) const override {}
};


class NewScope : public ASTNode
{
    public:
        node body;

        NewScope(node _body): 
            body(_body){}

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
            state.currentScope--;
        }

        //for frame size
        void count(CompilerState &state) const override {
            body->count(state);
        }
};

class If_Statement : public ASTNode
{
    public:
        node condition;
        node body;
    
        If_Statement(node _condition, node _body):
        condition(_condition), body(_body){}

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
        virtual void compile(std::ostream &dst, CompilerState &state) const override{
            state.ifVector.push_back(state.label());
            state.currentScope++;

            int reg1 = state.getTempReg(0);
            condition->compile(dst,state);
            state.registers[reg1]=0;
            
            dst<<"beq"<<" "<<"$"<<reg1<<" , "<<"$"<<"0"<<" , "<<"$L"<<(state.labelId)<<std::endl;
            dst<<"nop"<<std::endl;

            body->compile(dst,state);
            state.popScope();
            state.currentScope--;

            dst<<"b"<<" "<<"$L"<<state.ifVector[state.ifVector.size()-1]<<std::endl;

            dst<<"$L"<<state.label()<<std::endl;
        }

        //for frame size
        void count(CompilerState &state) const override {
            condition->count(state);
            body->count(state);
        }
};

class ElIf_Statement : public ASTNode
{
    public:
        node condition;
        node body;
    
        ElIf_Statement(node _condition, node _body):
        condition(_condition), body(_body){}

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
        virtual void compile(std::ostream &dst, CompilerState &state) const override{
            state.currentScope++;

            int reg1 = state.getTempReg(0);
            condition->compile(dst,state);
            state.registers[reg1]=0;
            
            dst<<"beq"<<" "<<"$"<<reg1<<" , "<<"$"<<"0"<<" , "<<"$L"<<(state.labelId)<<std::endl;
            dst<<"nop"<<std::endl;

            body->compile(dst,state);
            state.popScope();
            state.currentScope--;

            dst<<"b"<<" "<<"$L"<<state.ifVector[state.ifVector.size()-1]<<std::endl;

            dst<<"$L"<<state.label()<<std::endl;
        }

        //for frame size
        void count(CompilerState &state) const override {
            condition->count(state);
            body->count(state);
        }
};

class Else_Statement : public ASTNode
{
    public:
        node body;
    
        Else_Statement(node _body):
        body(_body){}

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
        virtual void compile(std::ostream &dst, CompilerState &state) const override{
            state.currentScope++;
            body->compile(dst,state);
            state.popScope();
            state.currentScope--;
        }

        //for frame size
        void count(CompilerState &state) const override {
            body->count(state);
        }
};

class While_Statement : public ASTNode
{
    public:
        node condition;
        node body;
    
        While_Statement(node _condition, node _body):
        condition(_condition), body(_body){}

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
        virtual void compile(std::ostream &dst, CompilerState &state) const override{
            state.currentScope++;

            int loopLabel = state.label();
            int exitLabel = state.label();
            dst<<"$L"<<loopLabel<<":"<<std::endl;

            int reg1 = state.getTempReg(0);
            condition->compile(dst,state);
            state.registers[reg1]=0;
            
            dst<<"beq"<<" "<<"$"<<reg1<<" , "<<"$"<<"0"<<" , "<<"$L"<<(exitLabel)<<std::endl;
            dst<<"nop"<<std::endl;

            body->compile(dst,state);
            state.popScope();
            state.currentScope--;

            dst<<"b"<<" "<<"$L"<<(loopLabel)<<std::endl;
            dst<<"nop"<<std::endl;
            dst<<"$L"<<exitLabel<<":"<<std::endl;
        }

        //for frame size
        void count(CompilerState &state) const override {
            condition->count(state);
            body->count(state);
        }
};

class Do_While_Statement : public ASTNode
{
    public:
        node body;
        node condition;
    
        Do_While_Statement(node _body, node _condition):
        body(_body), condition(_condition){}

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
            dst<<";"<<std::endl;
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
        virtual void compile(std::ostream &dst, CompilerState &state) const override{
            state.currentScope++;
            
            int loopLabel = state.label();
            int exitLabel = state.label();
            dst<<"$L"<<loopLabel<<":"<<std::endl;

            body->compile(dst,state);
            state.popScope();
            state.currentScope--;

            int reg1 = state.getTempReg(0);
            condition->compile(dst,state);
            state.registers[reg1]=0;
            
            dst<<"beq"<<" "<<"$"<<reg1<<" , "<<"$"<<"0"<<" , "<<"$L"<<(exitLabel)<<std::endl;
            dst<<"nop"<<std::endl;

            dst<<"b"<<" "<<"$L"<<(loopLabel)<<std::endl;
            dst<<"nop"<<std::endl;
            dst<<"$L"<<exitLabel<<":"<<std::endl;
        }

        //for frame size
        void count(CompilerState &state) const override {
            condition->count(state);
            body->count(state);
        }
};

#endif

#ifndef ast_Dec_Function_hpp
#define ast_Dec_Function_hpp

#include "ast_ASTNode.hpp"

class Function : public ASTNode
{
    public:
        std::string type;
        std::string id;
        node arguments;
        node body;
    
        Function(const std::string &_type,const std::string &_id, node _arguments, node _body):
        type(_type), id(_id), arguments(_arguments), body(_body){}

        //print tester
        virtual void print(std::ostream &dst, int &indent) const override
        {
            dst<<type<<" "<<id<<"(";
            arguments->print(dst,indent);
            dst<<"){"<<std::endl;
            indent++;
            body->print(dst,indent);
            indent--;
            dst<<"}"<<std::endl;
        }

        //translator 
        virtual void translate(std::ostream &dst, int &indent) const override{
            dst<<"def "<<id<<"(";
            arguments->translate(dst,indent);
            dst<<"):"<<std::endl;
            indent++;
            for(unsigned int i=0;i<globalVar.size();i++){
                for(int i=indent;i!=0;i--){
                    dst<<"\t";
                }
                dst<<"global "<<globalVar[i]<<std::endl;
            }
            body->translate(dst,indent);
            indent--;
        }

        //compiler 
        virtual void compile(std::ostream &dst, CompilerState &state) const override{
            dst<<"f"<<state.labelId<<":"<<std::endl;
            state.labelId++;
            //need function to count how many variables are used
            dst<<"addiu "<<"$sp"<<","<<"$sp"<<","<<"-"<<std::endl;
            dst<<"sw "<<"$fp"<<","<<"4($sp)"<<std::endl;
            dst<<"move "<<"$fp"<<"$sp"<<std::endl;
            //then stores arguments
            //do work
            
            //below needs to be put into the return
            dst<<"lw "<<"$fp"<<","<<"4($sp)"<<std::endl;
            dst<<"addiu "<<"$sp"<<","<<"$sp"<<","<<""<<std::endl;
            dst<<"j "<<"31"<<std::endl;
        }
};


#endif

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
        virtual void print(std::ostream &dst, PrintTransState &state) const override
        {
            dst<<type<<" "<<id<<"(";
            arguments->print(dst, state);
            dst<<"){"<<std::endl;
            state.indent++;
            body->print(dst, state);
            state.indent--;
            dst<<"}"<<std::endl;
        }

        //translator 
        virtual void translate(std::ostream &dst, PrintTransState &state) const override{
            dst<<"def "<<id<<"(";
            arguments->translate(dst, state);
            dst<<"):"<<std::endl;
            state.indent++;
            for(unsigned int i=0;i<state.gloVariables.size();i++){
                for(int i=state.indent;i!=0;i--){
                    dst<<"\t";
                }
                dst<<"global "<<state.gloVariables[i]<<std::endl;
            }
            body->translate(dst, state);
            state.indent--;
        }

        //compiler 
        virtual void compile(std::ostream &dst, CompilerState &state) const override{
            int varCount = 0;
            bodyCount(varCount);
            argsCount(varCount);
            varCount = varCount * 4;

            dst<<"f"<<state.labelId<<":"<<std::endl;
            state.labelId++;
            //need function to count how many variables are used
            dst<<"addiu "<<"$sp"<<" , "<<"$sp"<<" , "<<(-1*varCount)<<std::endl;
            dst<<"sw "<<"$fp"<<" , "<<"4($sp)"<<std::endl;
            dst<<"move "<<"$fp"<<" "<<"$sp"<<std::endl;
            
            state.currentScope++;

            //then stores arguments

            //do work
            body->compile(dst, state);

            state.popScope();

            //below needs to be put into the return
            dst<<"lw "<<"$fp"<<" , "<<"4($sp)"<<std::endl;
            dst<<"addiu "<<"$sp"<<" , "<<"$sp"<<" , "<<varCount<<std::endl;
            dst<<"j "<<"31"<<std::endl;
        }

        void bodyCount(int &cnt) const{
            body->count(cnt);
        }

        void argsCount(int &cnt) const{
            arguments->count(cnt);
        }
};


#endif

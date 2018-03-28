#ifndef ast_ArgumentNoType_hpp
#define ast_ArgumentNoType_hpp

#include "ast_ASTNode.hpp"

class ArgumentNoType : public ASTNode
{
    public:
        node arg;
        node nextArguments;
    
        ArgumentNoType( node _arg, node _nextArguments):
            arg(_arg), nextArguments(_nextArguments){}
        ArgumentNoType( node _arg):
            arg(_arg), nextArguments(NULL){}
        ArgumentNoType():
            arg(NULL), nextArguments(NULL){}

        //print tester
        virtual void print(std::ostream &dst, PrintTransState &state) const override
        {
            if(arg!=NULL){
                if(nextArguments!=NULL){
                    nextArguments->print(dst, state);
                    dst<<",";
                }
                arg->print(dst, state);
            }
        }

        //translator 
        virtual void translate(std::ostream &dst, PrintTransState &state) const override{
            if(arg!=NULL){
                if(nextArguments!=NULL){
                    nextArguments->translate(dst, state);
                    dst<<",";
                }
                arg->translate(dst, state);
            }
        }

        //compiler 
        virtual void compile(std::ostream &dst, CompilerState &state) const override{
            if(arg!=NULL){
                int reg1=state.getTempReg(0);
                arg->compile(dst,state);
                state.registers[reg1]=0;

                if(state.currentArgCount<4){
                    dst<<"addu"<<" "<<"$"<<(state.currentArgCount+4)<<" , "<<"$"<<reg1<<" , "<<"$0"<<std::endl;
                } else {
                    dst<<"sw"<<" "<<"$"<<reg1<<" , "<<(state.currentArgSize-state.currentArgCount*4)<<"(sp)"<<std::endl;
                }

                state.currentArgCount--;
                if(nextArguments!=NULL){
                    nextArguments->compile(dst, state);
                }
            }
        }

        virtual void count(CompilerState &state) const override {}
};

#endif

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
            dst<<")"<<std::endl;
            body->print(dst, state);
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
            state.funcVector.push_back(FunctionBind(type,id,state.labelId));

            state.varCount = 0;
            state.argCount = 0;
            state.argSpace = 0;
            arguments->count(state);
            body->count(state);

            state.funcVector[state.funcVector.size()-1].argSize=state.argSpace;

            int temp = state.varCount + state.argSpace + 8;
            if((temp%8)==(4)){
                temp +=4;
                state.functionOffset = temp;
                state.currentOffset = state.argSpace;
            } else {
                state.functionOffset = temp;
                state.currentOffset = state.argSpace - 4;
            }

            dst<<".global "<<id<<std::endl;
            dst<<".ent "<<id<<std::endl;
            dst<<".type "<<id<<", @function"<<std::endl<<std::endl;

            dst<<id<<":"<<std::endl;
            state.returnId=state.label();
            //need function to count how many variables are used
            dst<<"addiu"<<" "<<"$sp"<<" , "<<"$sp"<<" , "<<(-1*state.functionOffset)<<std::endl;
            dst<<"sw"<<" "<<"$31"<<" , "<<(state.functionOffset-4)<<"($sp)"<<std::endl;
            dst<<"sw"<<" "<<"$fp"<<" , "<<(state.functionOffset-8)<<"($sp)"<<std::endl;
            dst<<"add"<<" "<<"$"<<"fp"<<" , "<<"$"<<"sp"<<" , "<<"$0"<<std::endl;
            
            state.adjustStack(state.functionOffset);
            //then stores arguments
            arguments->compile(dst, state);

            //do work
            body->compile(dst, state);

            state.adjustStack(-state.functionOffset);

            //below needs to be put into the return
            dst<<"E"<<state.returnId<<":"<<std::endl;
            dst<<"add"<<" "<<"$"<<"sp"<<" , "<<"$"<<"fp"<<" , "<<"$0"<<std::endl;
            dst<<"lw"<<" "<<"$fp"<<" , "<<(state.functionOffset-8)<<"($sp)"<<std::endl;
            dst<<"sw"<<" "<<"$31"<<" , "<<(state.functionOffset-4)<<"($sp)"<<std::endl;
            dst<<"addiu"<<" "<<"$sp"<<" , "<<"$sp"<<" , "<<state.functionOffset<<std::endl;
            dst<<"j"<<" "<<"31"<<std::endl;
            dst<<"nop"<<std::endl<<std::endl;

            dst<<".end"<<std::endl;

            //dst<<state;
        }

        virtual void count(CompilerState &state) const override {}
};


#endif

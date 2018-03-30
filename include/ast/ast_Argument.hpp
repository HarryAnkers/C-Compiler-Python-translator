#ifndef ast_Argument_hpp
#define ast_Argument_hpp

#include "ast_ASTNode.hpp"

class Argument : public ASTNode
{
    public:
        std::string argType;
        std::string argId;
        node nextArguments;
        bool run=true;
    
        Argument(std::string &_argType, std::string &_argId, node _nextArguments):
            argType(_argType), argId(_argId), nextArguments(_nextArguments){}
        Argument(std::string &_argType, std::string &_argId):
            argType(_argType), argId(_argId), nextArguments(NULL){}
        Argument():
            argType(""), argId(""), nextArguments(NULL){run=false;}

        //print tester
        virtual void print(std::ostream &dst, PrintTransState &state) const override
        {
            if(run){
                if(nextArguments!=NULL){
                    nextArguments->print(dst, state);
                    dst<<",";
                }
                dst<<argType<<" "<<argId;
            }
        }

        //translator 
        virtual void translate(std::ostream &dst, PrintTransState &state) const override{
            if(run){
                if(nextArguments!=NULL){
                    nextArguments->translate(dst, state);
                    dst<<",";
                }
                dst<<argId;
            }
        }

        //compiler 
        virtual void compile(std::ostream &dst, CompilerState &state) const override{
            if(run){
                if(nextArguments!=NULL){
                    nextArguments->compile(dst,state);
                }
                int count =state.argCount;
                state.varVector.push_back(VariableBind(argId, argType, state.currentScope,((count*4)+state.functionOffset)));
                if(count<4){
                    if(((!argType.compare("char"))||(!argType.compare("signed char")))||
                        (!argType.compare("unsigned char"))){
                        dst<<"sb"<<" "<<"$"<<(count+4)<<" , "<<((count*state.typeToSize(argType))+state.functionOffset)<<"($fp)"<<std::endl;
                    } else if((!argType.compare("short"))||(!argType.compare("unsigned short"))){
                        dst<<"sh"<<" "<<"$"<<(count+4)<<" , "<<((count*state.typeToSize(argType))+state.functionOffset)<<"($fp)"<<std::endl;
                    } else{
                        dst<<"sw"<<" "<<"$"<<(count+4)<<" , "<<((count*state.typeToSize(argType))+state.functionOffset)<<"($fp)"<<std::endl;
                    }
                }
                state.argCount++;
            }
        }

        virtual void count(CompilerState &state) const override {
            if(run){
                if(nextArguments!=NULL){
                    nextArguments->count(state);
                }
                state.funcVector[(state.funcVector.size()-1)].arguments.push_back(argType);
            }
        }
};

#endif

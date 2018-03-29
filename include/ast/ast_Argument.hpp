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
                    std::string temp= argType;
                    int size=0;
                    if(!temp.compare("char")){ size = 4; }
                    else if(!temp.compare("signed char")){ size = 4; }
                    else if(!temp.compare("unsigned char")){ size = 4; }
                    else if(!temp.compare("short")){ size = 4; }
                    else if(!temp.compare("unsigned short")){ size = 4; }
                    else if(!temp.compare("int")){ size = 4; }
                    else if(!temp.compare("unsigned int")){ size = 4; }
                    else if(!temp.compare("long")){ size = 8; }
                    else if(!temp.compare("unsigned long")){ size = 8; }
                    else if(!temp.compare("long long")){ size = 16; }
                    else if(!temp.compare("unsigned long long")){ size = 16; }
                    else if(!temp.compare("float")){ size = 4; }
                    else if(!temp.compare("double")){ size = 8; }
                    else if(!temp.compare("long double")){ size = 32; }
                    else if(!temp.compare("void")){ size = 0; }
                    else{ throw std::invalid_argument( "type not defined" );}

                    dst<<"sw"<<" "<<"$"<<(count+4)<<" , "<<((count*size)+state.functionOffset)<<"($fp)"<<std::endl;
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

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
        virtual void compile(std::ostream &dst, CompilerState &state) const override{}
};

#endif

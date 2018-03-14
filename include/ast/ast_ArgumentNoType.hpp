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
        virtual void print(std::ostream &dst, int &indent) const override
        {
            if(arg!=NULL){
                if(nextArguments!=NULL){
                    nextArguments->print(dst, indent);
                    dst<<",";
                }
                arg->print(dst,indent);
            }
        }

        //translator 
        virtual void translate(std::ostream &dst, int &indent) const override{
            if(arg!=NULL){
                if(nextArguments!=NULL){
                    nextArguments->translate(dst, indent);
                    dst<<",";
                }
                arg->translate(dst,indent);
            }
        }

        //compiler 
        virtual void compile(std::ostream &dst, CompilerState &state) const override{}
};

#endif

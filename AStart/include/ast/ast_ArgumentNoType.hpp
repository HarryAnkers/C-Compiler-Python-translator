#ifndef ast_ArgumentNoType_hpp
#define ast_ArgumentNoType_hpp

#include "ast_ASTNode.hpp"

class ArgumentNoType : public ASTNode
{
    public:
        std::string argId;
        node nextArguments;
        bool run=true;
    
        ArgumentNoType( std::string &_argId, node _nextArguments):
        argId(_argId), nextArguments(_nextArguments){}
        ArgumentNoType():
        argId(""), nextArguments(NULL){run=false;}

        //print tester
        virtual void print(std::ostream &dst, int &indent) const override
        {
            if(run){
                if(nextArguments!=NULL){
                    nextArguments->print(dst, indent);
                    dst<<", ";
                }
                dst<<argId;
            }
        }

        //translator 
        virtual void translate(std::ostream &dst, int &indent) const override{
            if(run){
                if(nextArguments!=NULL){
                    nextArguments->translate(dst, indent);
                    dst<<", ";
                }
                dst<<argId;
            }
        }

        //compiler 
        virtual void compile(std::ostream &dst, int &indent) const override{}
};

#endif

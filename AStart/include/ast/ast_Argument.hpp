#ifndef ast_Argument_hpp
#define ast_Argument_hpp

#include "ast_MainBody.hpp"

class Argument : public MainBody
{
    public:
        string argId;
        string argType
        CompilerPtr nextArguments;
    
        Argument(string &_argId, string &_argType, CompilerPtr _nextArguments):
        argId(_argId), argType(_argType), nextArguments(_nextArguments){}
        Argument(string &_argId, string &_argType):
        argId(_argId), argType(_argType), nextArguments(NULL){}

        //print tester
        virtual void print(std::ostream &dst) const override
        {
            if(nextArguments!=NULL){
                nextArguments->print(dst);
                dst<<", "
            }
            argType->print(dst);
            argId->print(dst);
        }

        //translator 
        virtual void translate(std::ostream &dst) const override{};
};


#endif

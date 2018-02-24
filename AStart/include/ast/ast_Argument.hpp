#ifndef ast_Argument_hpp
#define ast_Argument_hpp

#include "ast_MainBody.hpp"

class Argument : public MainBody
{
    public:
        std::string argId;
        std::string argType;
        CompilerPtr nextArguments;
    
        Argument(std::string &_argId, std::string &_argType, CompilerPtr _nextArguments):
        argId(_argId), argType(_argType), nextArguments(_nextArguments){}
        Argument(std::string &_argId, std::string &_argType):
        argId(_argId), argType(_argType), nextArguments(NULL){}

        //print tester
        virtual void print(std::ostream &dst) const override
        {
            if(nextArguments!=NULL){
                nextArguments->print(dst);
                dst<<", ";
            }
            dst<<argId<<" "<<argType;
        }

        //translator 
        virtual void translate(std::ostream &dst) const override{};
};

#endif

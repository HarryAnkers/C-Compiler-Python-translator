#ifndef ast_Argument_hpp
#define ast_Argument_hpp

#include "ast_MainBody.hpp"

class Argument : public MainBody
{
    public:
        std::string argType;
        std::string argId;
        CompilerPtr nextArguments;
        bool run=true;
    
        Argument(std::string &_argType, std::string &_argId, CompilerPtr _nextArguments):
        argType(_argType), argId(_argId), nextArguments(_nextArguments){}
        Argument(std::string &_argType, std::string &_argId):
        argType(_argType), argId(_argId), nextArguments(NULL){}
        Argument():
        argType(""), argId(""), nextArguments(NULL){run=false;}

        //print tester
        virtual void print(std::ostream &dst, int &indent) const override
        {
            if(run){
                if(nextArguments!=NULL){
                    nextArguments->print(dst, indent);
                    dst<<", ";
                }
                dst<<argType<<" "<<argId;
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
};

#endif

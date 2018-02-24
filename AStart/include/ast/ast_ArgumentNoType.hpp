#ifndef ast_ArgumentNoType_hpp
#define ast_ArgumentNoType_hpp

#include "ast_MainBody.hpp"

class ArgumentNoType : public MainBody
{
    public:
        std::string argId;
        CompilerPtr nextArguments;
        bool skip=false;
    
        ArgumentNoType( std::string &_argId, CompilerPtr _nextArguments):
        argId(_argId), nextArguments(_nextArguments){}
        ArgumentNoType( std::string &_argId):
        argId(_argId), nextArguments(NULL){}
        ArgumentNoType():
        argId(NULL), nextArguments(NULL){skip=true;}

        //print tester
        virtual void print(std::ostream &dst, int &indent) const override
        {
            if(skip){
                if(nextArguments!=NULL){
                    nextArguments->print(dst, indent);
                    dst<<", ";
                }
                dst<<argId;
            }
        }

        //translator 
        virtual void translate(std::ostream &dst, int &indent) const override{
            if(skip){
                if(nextArguments!=NULL){
                    nextArguments->translate(dst, indent);
                    dst<<", ";
                }
                dst<<argId;
            }
        }
};

#endif

#ifndef ast_IfElseList_hpp
#define ast_IfElseList_hpp

#include "ast_MainBody.hpp"

class IfElseList : public MainBody
{
    public:
        CompilerPtr ifOrElse;
        CompilerPtr nextStatement;
    
        IfElseList(CompilerPtr _ifOrElse, CompilerPtr _nextStatement):
        ifOrElse(_ifOrElse), nextStatement(_nextStatement){}

        //print tester
        virtual void print(std::ostream &dst, int &indent) const override
        {
            ifOrElse->print(dst,indent);
            if(nextStatement!=NULL){
                nextStatement->print(dst,indent);
            }
        }

        //translator 
        virtual void translate(std::ostream &dst, int &indent) const override{
            ifOrElse->translate(dst,indent);
            if(nextStatement!=NULL){
                nextStatement->translate(dst,indent);
            }
        }
};


#endif

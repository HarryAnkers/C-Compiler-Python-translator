#ifndef ast_IfElseList_hpp
#define ast_IfElseList_hpp

#include "ast_ASTNode.hpp"

class IfElseList : public ASTNode
{
    public:
        node ifOrElse;
        node nextStatement;
    
        IfElseList(node _ifOrElse, node _nextStatement):
        ifOrElse(_ifOrElse), nextStatement(_nextStatement){}

        //print tester
        virtual void print(std::ostream &dst, PrintTransState &state) const override
        {
            ifOrElse->print(dst, state);
            if(nextStatement!=NULL){
                nextStatement->print(dst, state);
            }
        }

        //translator 
        virtual void translate(std::ostream &dst, PrintTransState &state) const override{
            ifOrElse->translate(dst, state);
            if(nextStatement!=NULL){
                nextStatement->translate(dst, state);
            }
        }

        //compiler 
        virtual void compile(std::ostream &dst, CompilerState &state) const override{}
};


#endif

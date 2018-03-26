#ifndef ast_Dec_Var_List_hpp
#define ast_Dec_Var_List_hpp

#include "ast_ASTNode.hpp"

class Dec_Var_List : public ASTNode
{
    public:
        node currDec;
        node nextDec;
    
        Dec_Var_List(node _currDec, node _nextDec):
            currDec(_currDec), nextDec(_nextDec){}
        Dec_Var_List(node _currDec):
            currDec(_currDec), nextDec(NULL){}

        //print tester
        virtual void print(std::ostream &dst, PrintTransState &state) const override
        {
            if(nextDec!=NULL){
                nextDec->print(dst,state);
                dst<<",";
            }
            currDec->print(dst,state);
        }

        //translator 
        virtual void translate(std::ostream &dst, PrintTransState &state) const override{
            if(nextDec!=NULL){
                nextDec->translate(dst,state);
                dst<<std::endl;
            }
            currDec->translate(dst,state);
        }

        //compiler 
        virtual void compile(std::ostream &dst, CompilerState &state) const override{
            if(nextDec!=NULL){
                nextDec->compile(dst,state);
            }
            currDec->compile(dst,state);
        }

        virtual void count(CompilerState &state) const override {
            if(nextDec!=NULL){
                nextDec->count(state);
            }
            currDec->count(state);
        }
};


#endif

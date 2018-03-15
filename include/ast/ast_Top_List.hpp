#ifndef ast_Top_List_hpp
#define ast_Top_List_hpp

#include "ast_ASTNode.hpp"

class Top_List : public ASTNode
{
public:
    node function;
    node nextFunction;

    Top_List(node _function, node _nextFunction):
        function(_function), nextFunction(_nextFunction){}

    //print tester
    virtual void print(std::ostream &dst, PrintTransState &state) const override
    {
        if(nextFunction!=NULL){
            nextFunction->print(dst, state);
            dst<<std::endl;
        }
        function->print(dst, state);
    }

    //translator 
    virtual void translate(std::ostream &dst, PrintTransState &state) const override{
        if(nextFunction!=NULL){
            nextFunction->translate(dst, state);
            dst<<std::endl;
        }
        function->translate(dst, state);
    }

    //compiler
    virtual void compile(std::ostream &dst, CompilerState &state) const override{
        if(nextFunction!=NULL){
            nextFunction->compile(dst, state);
            dst<<std::endl;
        }
        function->compile(dst, state);
    };
};


#endif

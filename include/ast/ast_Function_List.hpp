#ifndef ast_Function_List_hpp
#define ast_Function_List_hpp

#include "ast_ASTNode.hpp"

class Function_List : public ASTNode
{
public:
    node function;
    node nextFunction;

    Function_List(node _function, node _nextFunction):
        function(_function), nextFunction(_nextFunction){}

    //print tester
    virtual void print(std::ostream &dst, int &indent) const override
    {
        if(nextFunction!=NULL){
            nextFunction->print(dst, indent);
            dst<<std::endl;
        }
        function->print(dst, indent);
    }

    //translator 
    virtual void translate(std::ostream &dst, int &indent) const override{
        if(nextFunction!=NULL){
            nextFunction->translate(dst, indent);
            dst<<std::endl;
        }
        function->translate(dst, indent);
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

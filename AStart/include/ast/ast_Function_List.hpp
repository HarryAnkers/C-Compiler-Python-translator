#ifndef ast_Function_List_hpp
#define ast_Function_List_hpp

#include "ast_MainBody.hpp"

class Function_List : public MainBody
{
public:
    CompilerPtr function;
    CompilerPtr nextFunction;

    Function_List(CompilerPtr _function, CompilerPtr _nextFunction):
        function(_function), nextFunction(_nextFunction){}

    //print tester
    virtual void print(std::ostream &dst) const override
    {
        if(nextFunction!=NULL){
            nextFunction->print(dst);
            dst<<std::endl;
        }
        function->print(dst);
    }

    //translator 
    virtual void translate(std::ostream &dst) const override{};
};


#endif

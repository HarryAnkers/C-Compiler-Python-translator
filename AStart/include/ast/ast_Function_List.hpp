#ifndef ast_Function_hpp
#define ast_Function_hpp

#include "ast_MainBody.hpp"

class Function_List : public MainBody
{
private:
    CompilerPtr function;
    CompilerPtr nextFunction;
protected:
    Function_List(CompilerPtr _function, CompilerPtr _nextFunction):
        function(_function), nextFunction(_nextFunction){}
public:
    CompilerPtr getFunction(){return function;}
    CompilerPtr getNextFunction(){return nextFunction;}

    //print tester
    virtual void print(std::ostream &dst) const override
    {
        function->print(dst);
        dst<<std::endl;
        if(nextFunction!=NULL){
            nextFunction->print(dst);
            dst<<std::endl;
        }
    }

    //translator 
    //virtual void translate(std::ostream &dst) const =0;
};


#endif

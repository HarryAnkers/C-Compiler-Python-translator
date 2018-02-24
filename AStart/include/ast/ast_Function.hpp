#ifndef ast_Function_hpp
#define ast_Function_hpp

#include "ast_MainBody.hpp"


class Function : public MainBody
{
    public:
        std::string id;
        std::string type;
        CompilerPtr body;
        CompilerPtr arguments;
    
        Function(const std::string &_type,const std::string &_id, CompilerPtr _arguments, CompilerPtr _body):
        type(_type), id(_id), arguments(_arguments), body(_body){}

        //print tester
        virtual void print(std::ostream &dst) const override
        {
            dst<<type<<" ";
            dst<<id<<"(";
            arguments->print(dst);
            dst<<"){"<<std::endl;
            body->print(dst);
            dst<<"}"<<std::endl;
        }

        //translator 
        virtual void translate(std::ostream &dst) const override{};
};


#endif

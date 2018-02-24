#ifndef ast_Function_hpp
#define ast_Function_hpp

#include "ast_MainBody.hpp"


class Function : public MainBody
{
    public:
        std::string type;
        std::string id;
        CompilerPtr arguments;
        CompilerPtr body;
    
        Function(const std::string &_type,const std::string &_id, CompilerPtr _arguments, CompilerPtr _body):
        type(_type), id(_id), arguments(_arguments), body(_body){}

        //print tester
        virtual void print(std::ostream &dst, int &indent) const override
        {
            dst<<type<<" "<<id<<"(";
            arguments->print(dst,indent);
            dst<<"){"<<std::endl;
            indent++;
            body->print(dst,indent);
            indent--;
            dst<<"}"<<std::endl;
        }

        //translator 
        virtual void translate(std::ostream &dst, int &indent) const override{
            dst<<"def "<<id<<"(";
            arguments->translate(dst,indent);
            dst<<"):"<<std::endl;
            indent++;
            body->translate(dst,indent);
            indent--;
        }
};


#endif

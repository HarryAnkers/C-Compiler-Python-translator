#ifndef ast_Function_hpp
#define ast_Function_hpp

#include "ast_MainBody.hpp"


class Function : public MainBody
{
    private:
        std::string id;
        CompilerPtr body;
    protected:
        Function(std::string _id, CompilerPtr _body):
        id(_id), body(_body){}
    public:
        std::string getId(){return id;}
        CompilerPtr getBody(){return body;}

        //print tester
        virtual void print(std::ostream &dst) const override
        {
            dst<<"type ";
            dst<<id<<"(";
            dst<<id<<"){"<<std::endl;
            body->print(dst);
            dst<<"}"<<std::endl;
        }

        //translator 
        //virtual void translate(std::ostream &dst) const =0;
};


#endif

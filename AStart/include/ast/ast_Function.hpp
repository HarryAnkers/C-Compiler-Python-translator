#ifndef ast_Function_hpp
#define ast_Function_hpp

#include "ast_MainBody.hpp"

#include <string>

class Function : public MainBody
{
    private:
        string id;
        CompilerPtr body;
    protected:
        Function(string _id, CompilerPtr _body):
        id(_id), nextBody(_nextBody){}
    public:
        string getId(){return id;}
        ComplierPtr getBody(){return body;}

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
        virtual void translate(std::ostream &dst) const =0;
};


#endif

#ifndef ast_Function_hpp
#define ast_Function_hpp

#include "ast_MainBody.hpp"

#include <string>

class Function : public MainBody
{
    private:
        string id;
        CompilerPtr nextBody;
    protected:
        Function(string _id, CompilerPtr _nextBody):
        id(_id), nextBody(_nextBody){}
    public:
        string getId(){return id;}
        ComplierPtr getNextBody(){return nextBody;}

        //print tester
        virtual void print(std::ostream &dst) const =0;

        //translator 
        virtual void translate(std::ostream &dst) const =0;
};


#endif

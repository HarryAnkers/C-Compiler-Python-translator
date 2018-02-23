#ifndef ast_Body_hpp
#define ast_Body_hpp

#include "ast_MainBody.hpp"

class Body : public MainBody
{
    public:
        CompilerPtr statement;
        CompilerPtr nextBody;
    
        Body(CompilerPtr _statement, CompilerPtr _nextBody):
        statement(_statement), nextBody(_nextBody){}

        //print tester
        virtual void print(std::ostream &dst) const override
        {
            if(nextBody!=NULL){
                nextBody->print(dst);
            }
            statement->print(dst);
        }

        //translator 
        virtual void translate(std::ostream &dst) const override{};
};


#endif

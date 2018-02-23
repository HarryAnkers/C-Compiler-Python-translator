#ifndef ast_Body_hpp
#define ast_Body_hpp

#include "ast_MainBody.hpp"

class Body : public MainBody
{
    private:
        CompilerPtr statement;
        CompilerPtr nextBody;
    protected:
        Body(CompilerPtr _statement, CompilerPtr _nextBody):
        statement(_statement), nextBody(_nextBody){}
    public:
        CompilerPtr getStatement(){return statement;}
        CompilerPtr getNextBody(){return nextBody;}

        //print tester
        virtual void print(std::ostream &dst) const override
        {
            statement->print(dst);
            dst<<std::endl;
            if(nextBody!=NULL){
                nextBody->print(dst);
                dst<<std::endl;
            }
        }

        //translator 
        virtual void translate(std::ostream &dst) const override{};
};


#endif

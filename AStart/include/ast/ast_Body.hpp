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
        Body():
        statement(NULL), nextBody(NULL){}

        //print tester
        virtual void print(std::ostream &dst, int &indent) const override
        {
            if(statement!=NULL){
                if(nextBody!=NULL){
                    nextBody->print(dst,indent);
                }
                statement->print(dst,indent);
            }
        }

        //translator 
        virtual void translate(std::ostream &dst, int &indent) const override{
            
            if(statement!=NULL){
                
                if(nextBody!=NULL){
                    nextBody->translate(dst,indent);
                }

                statement->translate(dst,indent);
            }
        }
};


#endif

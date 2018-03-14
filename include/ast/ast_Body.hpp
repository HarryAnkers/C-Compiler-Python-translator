#ifndef ast_Body_hpp
#define ast_Body_hpp

#include "ast_ASTNode.hpp"

class Body : public ASTNode
{
    public:
        node statement;
        node nextBody;
    
        Body(node _statement, node _nextBody):
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

        //compiler 
        virtual void compile(std::ostream &dst, CompilerState &state) const override{}
};


#endif

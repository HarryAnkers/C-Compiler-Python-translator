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
        virtual void print(std::ostream &dst, PrintTransState &state) const override
        {
            if(statement!=NULL){
                if(nextBody!=NULL){
                    nextBody->print(dst, state);
                }
                statement->print(dst, state);
            }
        }

        //translator 
        virtual void translate(std::ostream &dst, PrintTransState &state) const override{
            if(statement!=NULL){
                
                if(nextBody!=NULL){
                    nextBody->translate(dst, state);
                }

                statement->translate(dst, state);
            }
        }

        //compiler 
        virtual void compile(std::ostream &dst, CompilerState &state) const override{
            if(statement!=NULL){
                if(nextBody!=NULL){
                    nextBody->compile(dst, state);
                }
                statement->compile(dst, state);
            }
        }

        void count(int &cnt) const {
            if(statement!=NULL){
                
                if(nextBody!=NULL){
                    nextBody->count(cnt);
                }
                statement->count(cnt);
            }
        }
};


#endif

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
                dst<<std::endl;
            }
        }

        //translator 
        virtual void translate(std::ostream &dst, PrintTransState &state) const override{
            if(statement!=NULL){
                if(nextBody!=NULL){
                    nextBody->translate(dst, state);
                }
                statement->translate(dst, state);
                dst<<std::endl;
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

        void count(CompilerState &state) const {
            if(statement!=NULL){
                if(nextBody!=NULL){
                    nextBody->count(state);
                }
                statement->count(state);
            }
        }
};


#endif

#ifndef ast_Future_Func_hpp
#define ast_Future_Func_hpp

#include "ast_ASTNode.hpp"

class Future_Func : public ASTNode
{
    public:
        std::string type;
        std::string id;
        node arguments;
    
        Future_Func(const std::string &_type,const std::string &_id, node _arguments):
        type(_type), id(_id), arguments(_arguments){}

        //print tester
        virtual void print(std::ostream &dst, PrintTransState &state) const override
        {
            dst<<type<<" "<<id<<"(";
            arguments->print(dst, state);
            dst<<");"<<std::endl;
        }

        //translator 
        virtual void translate(std::ostream &dst, PrintTransState &state) const override{
            dst<<"def "<<id<<"(";
            arguments->translate(dst, state);
            dst<<")"<<std::endl;
        }

        //compiler 
        virtual void compile(std::ostream &dst, CompilerState &state) const override{
            state.funcVector.push_back(FunctionBind(type,id));

            arguments->count(state);
        }

        virtual void count(CompilerState &state) const override {}
};


#endif

#ifndef ast_ASTNode_hpp
#define ast_ASTNode_hpp

#include <string>
#include <iostream>
#include <map>

#include <memory>

extern std::vector <std::string> globalVar;

class VariableBind
{
public:
    std::string Id;
    std::string type;
    int relativeToStack;
};

class CompilerState
{
public:
    CompilerState(){
        labelId=0;
    }
    ~CompilerState(){}
    int labelId;

};

class ASTNode;

typedef const ASTNode *node;

class ASTNode
{
public:
    virtual ~ASTNode()
    {}

    //print tester
    virtual void print(std::ostream &dst, int &indent) const =0;

    //compiler 
    virtual void translate(std::ostream &dst, int &indent) const =0;

    //compiler
    virtual void compile(std::ostream &dst, CompilerState &state) const =0;

    //these are all for first time called from cpp files
    void translate(std::ostream &dst) const{
        int indent=0;
        translate(dst, indent);
    }

    void print(std::ostream &dst) const{
        int indent=0;
        print(dst, indent);
    }

    void compile(std::ostream &dst) const{
        CompilerState state;
        compile(dst, state);
    }
};


#endif

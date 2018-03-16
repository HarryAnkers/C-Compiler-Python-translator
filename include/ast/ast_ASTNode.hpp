#ifndef ast_ASTNode_hpp
#define ast_ASTNode_hpp

#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <memory>

class VariableBind
{
public:
    std::string id;
    std::string type;
    int scope;

    VariableBind(std::string _id, std::string _type, int _scope):
        id(_id),type(_type),scope(_scope){}

    ~VariableBind(){}

    friend std::ostream& operator<< (std::ostream &o, VariableBind b){
    o << "element: "<<b.id<<", type: "<< b.type << ", scope: " << b.scope;
    return o;
  }
};

class CompilerState
{
public:
    int labelId;
    std::vector<VariableBind> varVector;
    int currentScope;

    CompilerState():
        labelId(0), currentScope(0) {}
    ~CompilerState(){}

    void popScope(){
        bool stop = false;
        int i = 0;
        while((stop == false) && (i >= 0)){
            i=varVector.size()-1;
            if(varVector[i].scope==currentScope){
                varVector.pop_back();
            } else {
                stop = true;
                currentScope--;
            }
        }
    }
};

class PrintTransState
{
public:
    int indent;
    std::vector<std::string> gloVariables;

    PrintTransState():
        indent(0) {}

    ~PrintTransState(){}
};

class ASTNode;

typedef const ASTNode *node;

class ASTNode
{
public:
    virtual ~ASTNode()
    {}

    //print tester
    virtual void print(std::ostream &dst, PrintTransState &state) const =0;

    //compiler 
    virtual void translate(std::ostream &dst, PrintTransState &state) const =0;

    //compiler
    virtual void compile(std::ostream &dst, CompilerState &state) const =0;

    //for counting elements in tree
    virtual void count(int &varCount) const{}

    //these are all for first time called from cpp files
    void translate(std::ostream &dst) const{
        PrintTransState state;
        translate(dst, state);
    }

    void print(std::ostream &dst) const{
        PrintTransState state;
        print(dst, state);
    }

    void compile(std::ostream &dst) const{
        CompilerState state;
        compile(dst, state);
    }
};


#endif

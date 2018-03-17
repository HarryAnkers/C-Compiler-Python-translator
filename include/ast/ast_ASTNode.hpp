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
    int relativeStack;

    VariableBind(std::string _id, std::string _type, int _scope, int _relativeStack):
        id(_id),type(_type),scope(_scope), relativeStack(_relativeStack){}

    ~VariableBind(){}

    friend std::ostream& operator<< (std::ostream &o, VariableBind b){
    o << "element: "<<b.id<<", type: "<< b.type << ", scope: " << b.scope << ", relativeStack: " << b.relativeStack;
    return o;
  }
};

class CompilerState
{
public:
    int labelId;
    std::vector<VariableBind> varVector;
    int currentScope;
    int registers[32];
    int currentOffset;

    CompilerState():
        labelId(0), currentScope(0), currentOffset(-4) {
            for(int i=0;i<32;i++){
                registers[i]=0;
            }
        }
    ~CompilerState(){}

    void adjustStack(int offset){
        for(int i=varVector.size()-1;i>=0;i--){
            varVector[i].relativeStack=+offset;
        }
    }

    int offset(){
        currentOffset+=4;
        return currentOffset;
    }

    int getTempReg(int x){
        for(int i=2;i<4;i++){
            if(registers[i]!=0){
                registers[i]=x
                return i;
            }
        } for(int i=8;i<16;i++){
            if(registers[i]!=0){
                registers[i]=x
                return i;
            }
        }

        //NEED TO FIX THIS BUT WILL WORK FOR NOW

        std::cout<<"no free registers"<<std::endl;
    }

    void popScope(){
        bool stop = false;
        int i = 0;
        if(varVector.size()!=0){
            while((stop == false) && (i >= 0)){
                i=varVector.size()-1;
                if(varVector[i].scope==currentScope){
                    varVector.pop_back();
                } else {
                    stop = true;
                }
            }
            std::cout<<"pre adjust"<<std::endl;
            adjustStack(-1*((i*4)+8));
            std::cout<<"adjust"<<std::endl;
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

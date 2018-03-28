#ifndef ast_ASTNode_hpp
#define ast_ASTNode_hpp

#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <memory>
#include <sstream>

class FunctionBind
{
    public:
    std::string type;
    std::string id;
    std::vector<std::string> arguments;
    int argSize;

    FunctionBind(std::string _type, std::string _id):
        type(_type),id(_id){}

    friend std::ostream& operator<< (std::ostream &o, FunctionBind b){
        o << "type: "<<b.type<< "id: "<<b.id;
        return o;
    }
};

class VariableBind
{
public:
    std::string id;
    std::string type;
    int scope;
    int stackOffset;
    bool isTemp;

    VariableBind(std::string _id, std::string _type, int _scope, int _stackOffset):
        id(_id),type(_type),scope(_scope), stackOffset(_stackOffset), isTemp(false){}
    
    VariableBind(int _stackOffset, bool _isTemp):
        stackOffset(_stackOffset), isTemp(_isTemp){}

    ~VariableBind(){}

    friend std::ostream& operator<< (std::ostream &o, VariableBind b){
        o << "element: "<<b.id<<", type: "<< b.type << ", scope: " << b.scope << ", stackOffset: " << b.stackOffset;
        return o;
    }
};

class GloVarBind
{
public:
    std::string id;
    std::string type;

    GloVarBind(std::string _id, std::string _type):
        id(_id),type(_type){}

    ~GloVarBind(){}

    friend std::ostream& operator<< (std::ostream &o, GloVarBind b){
        o << "element: "<<b.id<<", type: "<< b.type;
        return o;
    }
};

class CompilerState
{
public:
    int labelId;
    std::vector<VariableBind> varVector;
    std::vector<FunctionBind> funcVector;
    std::vector<GloVarBind> gloVarVector;
    std::vector<int> ifVector;

    std::string currentType;
    
    int currentScope;
    int currentArgCount;
    int currentFCall;
    int currentArgSize;
    int registers[32];
    int currentOffset;
    int returnId;
    int varCount;
    int argCount;
    int argSpace;
    int functionOffset;

    CompilerState():
        labelId(0), currentScope(0), currentOffset(-4), returnId(0) {
            for(int i=0;i<32;i++){
                registers[i]=0;
            }
        }
    ~CompilerState(){}

    void adjustStack(int offset){
        for(int i=varVector.size()-1;i>=0;i--){
            varVector[i].stackOffset=+offset;
        }
    }

    int label(){
        labelId++;
        return labelId-1;
    }

    int offset(){
        currentOffset+=4;
        return currentOffset;
    }

    int getTempReg(int x){
        for(int i=2;i<4;i++){
            if(registers[i]==0){
                registers[i]=x;
                return i;
            }
        } for(int i=8;i<16;i++){
            if(registers[i]==0){
                registers[i]=x;
                return i;
            }
        }
        return -1;
        std::cout<<"no free registers"<<std::endl;
    }

    void fullRegCheck(std::ostream &dst){

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
        }
    }

    std::string toHex(int dec){
        std::stringstream stream;
        stream << std::hex << dec;
        std::string result = stream.str();
        return result;
    }

    friend std::ostream& operator<< (std::ostream &o, CompilerState b){
        o<<std::endl<<" registers that are still being used :"<<std::endl;
        for(int i=0; i<32;i++){
            if(b.registers[i]!=0){
                o<<"regNo - "<<i<<std::endl;
            }
        }
        return o;
    }
};

class PrintTransState
{
public:
    int indent;
    std::vector<std::string> gloVariables;

    std::string currentType;

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
    virtual void count(CompilerState &state) const =0;

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

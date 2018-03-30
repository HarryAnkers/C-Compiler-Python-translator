#ifndef ast_ASTNode_hpp
#define ast_ASTNode_hpp

#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <memory>
#include <sstream>

class ArrayBind
{
    public:
    std::string type;
    std::string id;
    std::vector<int> elementOffset;
    int size;

    ArrayBind(std::string _type, std::string _id):
        type(_type),id(_id){}

    friend std::ostream& operator<< (std::ostream &o, ArrayBind b){
        for(unsigned int i=0;i<b.elementOffset.size();i++){
            o << "i:"<<i<<"-type: "<<b.type<< ",id: "<<b.id<<",offset "<<b.elementOffset[i]<<std::endl;
        }
        return o;
    }
};

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
    std::vector<VariableBind> varVector;
    std::vector<FunctionBind> funcVector;
    std::vector<GloVarBind> gloVarVector;
    std::vector<ArrayBind> ArrayVector;
    std::vector<int> ifVector;
    std::vector<int> tempStack;

    std::string currentType;
    std::string currentId;

    int stackChangeNeeded;
    int labelId;
    int full;
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
    int arrayCounter;
    int currentArraySize;

    CompilerState():
        stackChangeNeeded(0), labelId(0), currentScope(0), currentOffset(-4), returnId(0) {
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

    int offset(std::string temp){
        currentOffset+=typeToSize(temp);
        return currentOffset;
    }

    int typeToSize(std::string temp){
        int size;
        if(!temp.compare("char")){ size = 4; }
        else if(!temp.compare("signed char")){ size = 4; }
        else if(!temp.compare("unsigned char")){ size = 4; }
        else if(!temp.compare("short")){ size = 4; }
        else if(!temp.compare("unsigned short")){ size = 4; }
        else if(!temp.compare("int")){ size = 4; }
        else if(!temp.compare("unsigned int")){ size = 4; }
        else if(!temp.compare("long")){ size = 8; }
        else if(!temp.compare("unsigned long")){ size = 8; }
        else if(!temp.compare("long long")){ size = 16; }
        else if(!temp.compare("unsigned long long")){ size = 16; }
        else if(!temp.compare("float")){ size = 4; }
        else if(!temp.compare("double")){ size = 8; }
        else if(!temp.compare("long double")){ size = 32; }
        else if(!temp.compare("void")){ size = 0; }
        else{ throw std::invalid_argument( "type not defined" );}
        return size;
    }

    int getTempReg(int x,std::ostream &dst){
        for(int i=2;i<4;i++){
            if(registers[i]==0){
                registers[i]=x;
                full=0;
                return i;
            }
        } for(int i=8;i<16;i++){
            if(registers[i]==0){
                registers[i]=x;
                full=0;
                return i;
            }
        }
        throw std::invalid_argument( "ran out of registers" );
        /*if(x==0){
            if(registers[21]==0){
                stackChangeNeeded++;
                return 21;
            } else {
                stackChangeNeeded++;
                return 22;
            }
        }
        else{
            registers[21]=1;
            full=1;
            int adjustment=typeToSize("int");
            functionOffset+=adjustment;
            dst<<"addiu"<<" "<<"$fp"<<" , "<<"$fp"<<" , "<<(-1*adjustment)<<std::endl;
            tempStack.push_back(offset("int"));
            adjustStack(adjustment);
            return 21;
        }*/
    }

    void ifLoad(std::ostream &dst, int x){/*
        if((x==21)||(x=22)){
            dst<<"lw"<<" "<<"$"<<x<<" , "<<tempStack[tempStack.size()-1]<<"($fp)"<<std::endl;
        }*/
    }

    void ifFull(std::ostream &dst){/*
        while(stackChangeNeeded>0){
            tempStack.pop_back();
            stackChangeNeeded--;
        }
        if(full==1){
            registers[21]=0;
            dst<<"sw"<<" "<<"$"<<"21"<<" , "<<tempStack[tempStack.size()-1]<<"($fp)"<<std::endl;
        }*/
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

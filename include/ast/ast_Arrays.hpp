#ifndef ast_Arrays_hpp
#define ast_Arrays_hpp

#include "ast_ASTNode.hpp"

class DeclareArray : public ASTNode{
    public:
        std::string type;
        std::string id;
        int sizeExpr;
        node valList;
    
        DeclareArray(std::string _type, std::string _id, int _sizeExpr):
            type(_type), id(_id), sizeExpr(_sizeExpr), valList(NULL){}
        DeclareArray(std::string _type, std::string _id, int _sizeExpr, node _valList):
            type(_type), id(_id), sizeExpr(_sizeExpr), valList(_valList){}
        DeclareArray(int x, std::string _type, std::string _id, node _valList):
            type(_type), id(_id), sizeExpr(-1), valList(_valList){}

        //print tester
        virtual void print(std::ostream &dst, PrintTransState &state) const override
        {
            for(int i=state.indent;i!=0;i--){
                dst<<"\t";
            }
            dst<<type<<" "<<id<<"[";
            if(sizeExpr!=-1){
                dst<<sizeExpr; 
            }
            dst<<"]";
            if(valList!=NULL){
                dst<<" = {";
                valList->print(dst,state);
                dst<<"};";
            } else { dst<<";"; }
        }

        //translator 
        virtual void translate(std::ostream &dst, PrintTransState &state) const override{
            for(int i=state.indent;i!=0;i--){
                dst<<"\t";
            }
            dst<<id;
            if(valList!=NULL){
                dst<<" = [";
                valList->translate(dst,state);
                dst<<"]";
            } else {
                dst<<" = []";
            }
        }

        //compiler 
        virtual void compile(std::ostream &dst, CompilerState &state) const override{
            state.currentType=type;
            state.currentArraySize=sizeExpr;
            state.currentId=id;
            state.arrayCounter=1;
            state.ArrayVector.push_back(ArrayBind(type,id));

            if(valList!=NULL){
                valList->compile(dst,state);
            }

            std::cout<<"no more next val"<<std::endl;
            if((state.currentArraySize!=-1)&&(state.arrayCounter!=state.currentArraySize)){
                std::cout<<"didn't match"<<std::endl;
                for(int i=state.arrayCounter;i!=state.currentArraySize;i++){
                    for(int i=state.ArrayVector.size()-1;i>=0;i--){
                        if(!state.ArrayVector[i].id.compare(state.currentId)){
                            int offset = state.offset(state.currentType);
                            state.ArrayVector[i].elementOffset.push_back(state.offset(state.currentType));
                            dst<<"sw "<<"$"<<"0"<<" , "<<offset<<"($fp)"<<std::endl;
                        }
                    }
                }
            }
        }

        virtual void count(CompilerState &state) const override {
            if(sizeExpr!=-1){
                int size;
                std::string temp=type;

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

                state.varCount=state.varCount+(size*sizeExpr);
            } else {
                state.arrayCounter=0;
                valList->count(state);
                int size;
                std::string temp=type;

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

                state.varCount=state.varCount+(size*state.arrayCounter);
            }
        }
};

class ValList : public ASTNode{
    public:
        node currentVal;
        node nextVal;
    
        ValList(node _currentVal, node _nextVal):
            currentVal(_currentVal), nextVal(_nextVal){}
        ValList(node _currentVal):
            currentVal(_currentVal), nextVal(NULL){}
        ValList():
            currentVal(NULL), nextVal(NULL){}

        //print tester
        virtual void print(std::ostream &dst, PrintTransState &state) const override
        {
            if(currentVal!=NULL){
                if(nextVal!=NULL){
                    nextVal->print(dst,state);
                    dst<<",";
                }
                currentVal->print(dst,state);
            }
        }

        //translator 
        virtual void translate(std::ostream &dst, PrintTransState &state) const override{
            if(currentVal!=NULL){
                if(nextVal!=NULL){
                    nextVal->translate(dst,state);
                    dst<<",";
                }
                currentVal->translate(dst,state);
            }
        }

        //compiler 
        virtual void compile(std::ostream &dst, CompilerState &state) const override{
            if(currentVal!=NULL){
                if(nextVal!=NULL){
                    std::cout<<"inside next val"<<std::endl;
                    nextVal->compile(dst,state);
                    state.arrayCounter++;
                    std::cout<<"counter = "<<state.arrayCounter<<std::endl;
                }
                int reg1 = state.getTempReg(0);
                int offset = state.offset(state.currentType);
                for(int i=state.ArrayVector.size()-1;i>=0;i--){
                    if(!state.ArrayVector[i].id.compare(state.currentId)){
                        state.ArrayVector[i].elementOffset.push_back(offset);
                    }
                }

                currentVal->compile(dst,state);
                dst<<"sw "<<"$"<<reg1<<" , "<<offset<<"($fp)"<<std::endl;
                state.registers[reg1]=0;
            } else {
                for(int j=state.ArrayVector.size()-1;j>=0;j--){
                    if(!state.ArrayVector[j].id.compare(state.currentId)){
                        for(int i=0;i<state.currentArraySize;i++){
                            int offset = state.offset(state.currentType);
                            state.ArrayVector[j].elementOffset.push_back(offset);
                            dst<<"sw "<<"$"<<"0"<<" , "<<offset<<"($fp)"<<std::endl;
                        }
                        return;
                    }
                }
                throw std::invalid_argument( "array is not defined" );
            }
        }

        virtual void count(CompilerState &state) const override {
            if(currentVal!=NULL){
                if(nextVal!=NULL){
                    nextVal->count(state);
                }
                state.arrayCounter++;
            }
        }
};

#endif
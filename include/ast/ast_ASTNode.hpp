#ifndef ast_ASTNode_hpp
#define ast_ASTNode_hpp

#include <string>
#include <iostream>
#include <map>

#include <memory>

extern std::vector <std::string> globalVar;

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
    virtual void compile(std::ostream &dst) const =0;
};


#endif

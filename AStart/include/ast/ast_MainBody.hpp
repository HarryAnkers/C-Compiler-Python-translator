#ifndef ast_MainBody_hpp
#define ast_MainBody_hpp

#include <string>
#include <iostream>
#include <map>

#include <memory>

class MainBody;

typedef const MainBody *CompilerPtr;

class MainBody
{
public:
    virtual ~MainBody()
    {}

    //print tester
    virtual void print(std::ostream &dst, int &indent) const =0;

    //translator 
    virtual void translate(std::ostream &dst, int &indent) const =0;
};


#endif

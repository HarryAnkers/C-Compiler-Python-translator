#ifndef ast_body_hpp
#define ast_body_hpp

#include <string>
#include <iostream>
#include <map>

#include <memory>

class MainBody;

typedef const MainBody *MainBodyPtr;

class Expression
{
public:
    virtual ~MainBody()
    {}

    //translate
    virtual void translate(std::ostream &dst) const =0;

    //print to verify input
    virtual void print(std::ostream &dst) const = 0;
};


#endif

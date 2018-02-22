#ifndef ast_body_hpp
#define ast_body_hpp

#include <string>
#include <iostream>
#include <map>

#include <memory>

class Body;

typedef const Body *BodyPtr;

class Expression
{
public:
    virtual ~Body()
    {}

    //! Tell and expression to print itself to the given stream
    virtual void translate(std::ostream &dst) const =0;

    //print to verify input
    virtual void print(std::ostream &dst) const = 0;
};


#endif

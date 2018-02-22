#ifndef ast_body_hpp
#define ast_body_hpp

#include <string>
#include <iostream>
#include <map>

#include <memory>

#include "ast_main_body.hpp"

class MainBody;

typedef const MainBody *MainBodyPtr;

class MainBody
{
private: 
    Ptr mainFunc
public:
    virtual ~MainBody(ptr _mainFunc)
    mainFunc(_mainFunc){}

    //translate
    virtual void translate(std::ostream &dst) const =0;

    //print to verify input
    virtual void print(std::ostream &dst) const = 0;
};


#endif

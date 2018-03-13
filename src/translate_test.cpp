#include "ast.hpp"

std::vector <std::string> globalVar;

int main()
{
    const ASTNode *ast=parseAST();
    
    int i=0;
    ast->translate(std::cout,i);
    std::cout<<std::endl;
    std::cout<<"# Boilerplat"<<std::endl;
    std::cout<<"if __name__ == \"__main__\":"<<std::endl;
    std::cout<<"    import sys"<<std::endl;
    std::cout<<"    ret=main()"<<std::endl;
    std::cout<<"    sys.exit(ret)"<<std::endl;

    return 0;
}

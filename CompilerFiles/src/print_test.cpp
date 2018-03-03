#include "ast.hpp"

std::vector <std::string> globalVar;

int main()
{
    const ASTNode *ast=parseAST();
    
    int i=0;
    ast->print(std::cout,i);
    std::cout<<std::endl;

    return 0;
}

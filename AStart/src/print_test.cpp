#include "ast.hpp"

int main()
{
    const ASTNode *ast=parseAST();
    
    int i=0;
    ast->print(std::cout,i);
    std::cout<<std::endl;

    return 0;
}

#include "ast.hpp"

int main()
{
    const ASTNode *ast=parseAST();
    
    ast->compile(std::cout);
    std::cout<<std::endl;

    return 0;
}

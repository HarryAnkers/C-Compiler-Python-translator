#include "ast.hpp"

int main()
{
    const MainBody *ast=parseAST();
    
    ast->translate(std::cout);
    std::cout<<std::endl;

    return 0;
}

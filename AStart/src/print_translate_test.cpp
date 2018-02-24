#include "ast.hpp"

int main()
{
    const MainBody *ast=parseAST();
    
    int i=0;
    ast->print(std::cout,i);
    std::cout<<std::endl<<std::endl;
    ast->translate(std::cout,i);
    std::cout<<std::endl;

    return 0;
}

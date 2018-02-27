#include "ast.hpp"

int main(int argc = 4, char *argv[] = NULL)
{
    /*const MainBody *ast=parseAST();
    
    int i=0;
    ast->print(std::cout,i);
    std::cout<<std::endl<<std::endl;
    ast->translate(std::cout,i);
    std::cout<<std::endl;
    std::cout<<std::endl;*/

   int i = 0;
   
   std::cout<< "START " << std::endl;          
              freopen (argv[2],"r",stdin);
 
    const MainBody *ast=parseAST();
              std::cout<< std::endl;    
             
              freopen (argv[4],"w",stdout);
              std::string test = argv[1];
              if (test == "--translate") {
                //std::cout<< "The Python Equivalent: " << std::endl;
                ast->translate(std::cout, i);
                std::cout<<std::endl;
              }

    
    
    std::cout<<"# Boilerplat"<<std::endl;
    std::cout<<"if __name__ == \"__main__\":"<<std::endl;
    std::cout<<"    import sys"<<std::endl;
    std::cout<<"    ret=main()"<<std::endl;
    std::cout<<"    sys.exit(ret)"<<std::endl;

    return 0;
}

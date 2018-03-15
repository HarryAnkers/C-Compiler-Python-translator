#include "ast.hpp"

int main(int argc = 4, char *argv[] = NULL)
{
  std::cout<< "START " << std::endl;          
  freopen (argv[2],"r",stdin);

  const ASTNode *ast=parseAST();
  
  std::cout<< std::endl;    

  freopen (argv[4],"w",stdout);
  std::string test = argv[1];
  if (test == "--translate") {
    //std::cout<< "The Python Equivalent: " << std::endl;
    ast->translate(std::cout);
    std::cout<<std::endl;

    std::cout<<"# Boilerplat"<<std::endl;
    std::cout<<"if __name__ == \"__main__\":"<<std::endl;
    std::cout<<"    import sys"<<std::endl;
    std::cout<<"    ret=main()"<<std::endl;
    std::cout<<"    sys.exit(ret)"<<std::endl;
  } 
  else if (test == "--compile") {
    ast->compile(std::cout);
    std::cout<<std::endl;
  }

  return 0;
}

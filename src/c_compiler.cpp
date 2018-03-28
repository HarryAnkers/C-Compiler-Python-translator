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
    //std::cout<<std::endl;

    /*std::cout<<".global assign"<<std::endl;
    std::cout<<".ent assign"<<std::endl;
    std::cout<<".type assign, @function"<<std::endl;

    std::cout<<"assign:"<<std::endl;
    std::cout<<"addiu $sp,$sp,-8"<<std::endl;
    std::cout<<"sw $31,4($sp)"<<std::endl;
    std::cout<<"sw $fp,0($sp)"<<std::endl;
    std::cout<<"add $fp,$sp,$0"<<std::endl;
    std::cout<<"sw $4,8($fp)"<<std::endl;
    std::cout<<"addi $2,$0,0x0"<<std::endl;
    std::cout<<"sw $2,8($fp)"<<std::endl;
    std::cout<<"lw $2,8($fp)"<<std::endl;
    std::cout<<"add $2,$2,$0"<<std::endl;
    std::cout<<"b $E0"<<std::endl;
    std::cout<<"$E0:"<<std::endl;
    std::cout<<"add $sp,$fp,$0"<<std::endl;
    std::cout<<"lw $fp,0($sp)"<<std::endl;
    std::cout<<"sw $31,4($sp)"<<std::endl;
    std::cout<<"addiu $sp,$sp,8"<<std::endl;
    std::cout<<"j 31"<<std::endl;
    std::cout<<"nop"<<std::endl;

    std::cout<<".end assign"<<std::endl;*/


    std::cout<<"  .file	1 \"assign_const.c\""<<std::endl;
    std::cout<<"  .section .mdebug.abi32"<<std::endl;
    std::cout<<"  .previous"<<std::endl;
    std::cout<<"  .nan	legacy"<<std::endl;
    std::cout<<"  .abicalls"<<std::endl;
    std::cout<<"  .text"<<std::endl;
    std::cout<<"  .align	2"<<std::endl;
    std::cout<<"  .globl	assign"<<std::endl;
    std::cout<<"  .set	nomips16"<<std::endl;
    std::cout<<"  .set	nomicromips"<<std::endl;
    std::cout<<"  .ent	assign"<<std::endl;
    std::cout<<"  .type	assign, @function"<<std::endl;
    std::cout<<"assign:"<<std::endl;
    std::cout<<"  .frame	$fp,8,$31		# vars= 0, regs= 1/0, args= 0, gp= 0"<<std::endl;
    std::cout<<"  .mask	0x40000000,-4"<<std::endl;
    std::cout<<"  .fmask	0x00000000,0"<<std::endl;
    std::cout<<"  .set	noreorder"<<std::endl;
    std::cout<<"  .set	nomacro"<<std::endl;
    std::cout<<"  addiu	$sp,$sp,-8"<<std::endl;
    std::cout<<"  sw	$fp,4($sp)"<<std::endl;
    std::cout<<"  move	$fp,$sp"<<std::endl;
    std::cout<<"  sw	$4,8($fp)"<<std::endl;
    std::cout<<"  sw	$0,8($fp)"<<std::endl;
    std::cout<<"  lw	$2,8($fp)"<<std::endl;
    std::cout<<"  move	$sp,$fp"<<std::endl;
    std::cout<<"  lw	$fp,4($sp)"<<std::endl;
    std::cout<<"  addiu	$sp,$sp,8"<<std::endl;
    std::cout<<"  j	$31"<<std::endl;
    std::cout<<"  nop"<<std::endl;

    std::cout<<"  .set	macro"<<std::endl;
    std::cout<<"  .set	reorder"<<std::endl;
    std::cout<<"  .end	assign"<<std::endl;
	  std::cout<<"  .size	assign, .-assign"<<std::endl;
	  std::cout<<"  .ident	\"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.9) 5.4.0 20160609\""<<std::endl;
  }

  return 0;
}

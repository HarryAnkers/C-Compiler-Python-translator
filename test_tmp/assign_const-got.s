.global assign
.ent assign
.type assign, @function

assign:
addiu $sp , $sp , -8
sw $31 , 4($sp)
sw $fp , 0($sp)
add $fp , $sp , $0
sw $4 8($fp)
addi $2 , $0 , 0x0
sw $2 , 8($fp)
lw $2 , 8($fp)
add $2 , $2 , $0
b $E0
$E0:
add $sp , $fp , $0
lw $fp , 0($sp)
sw $31 , 4($sp)
addiu $sp , $sp , 8
j 31
nop

.end assign
  .file	1 "assign_const.c"
  .section .mdebug.abi32
  .previous
  .nan	legacy
  .abicalls
  .text
  .align	2
  .globl	assign
  .set	nomips16
  .set	nomicromips
  .ent	assign
  .type	assign, @function
assign:
  .frame	$fp,8,$31		# vars= 0, regs= 1/0, args= 0, gp= 0
  .mask	0x40000000,-4
  .fmask	0x00000000,0
  .set	noreorder
  .set	nomacro
  addiu	$sp,$sp,-8
  sw $fp,4($sp)
  move	$fp,$sp
  sw	$4,8($fp)
  sw	$0,8($fp)
  lw	$2,8($fp)
  move	$sp,$fp
  lw	$fp,4($sp)
  addiu	$sp,$sp,8
  j	$31
  nop
  .set	macro
  .set	reorder
  .end	assign
  .size	assign, .-assign
  .ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.9) 5.4.0 20160609"

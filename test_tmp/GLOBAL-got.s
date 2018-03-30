x:
.word 10
.align 2
.type x, @object
.size x, 4


.globl global
.ent global
.type global, @function
global:
addiu $sp , $sp , -8
sw $31 , 4($sp)
sw $fp , 0($sp)
move $fp , $sp
addiu $2 , $0 , 0x0
sw $2 , %lo(x)($2)
lui $2 , %hi(x)
lw $2 , %lo(x)($2)
addu $2 , $2 , $0
b $E0
nop
$E0:
addu $sp , $fp , $0
lw $fp , 0($sp)
lw $31 , 4($sp)
addiu $sp , $sp , 8
j $31
nop
.end global

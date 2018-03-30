.globl x
.data 
.align 2
x:
.word 20
.text

.globl global
.ent global
.type global, @function
global:
addiu $sp , $sp , -8
sw $31 , 4($sp)
sw $fp , 0($sp)
move $fp , $sp
addiu $3 , $0 , 0xa
sw $3 , %lo(x)($2)
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

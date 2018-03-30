.globl arg4
.ent arg4
.type arg4, @function
arg4:
addiu $sp , $sp , -8
sw $31 , 4($sp)
sw $fp , 0($sp)
move $fp , $sp
sw $4 , 8($fp)
sw $5 , 12($fp)
sw $6 , 16($fp)
sw $7 , 20($fp)
lw $2 , 8($fp)
lw $3 , 12($fp)
addu $2 , $2 , $3
lw $3 , 16($fp)
addu $2 , $2 , $3
lw $3 , 20($fp)
addu $2 , $2 , $3
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
.end arg4

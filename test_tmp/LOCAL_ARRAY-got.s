.globl arr
.ent arr
.type arr, @function
arr:
addiu $sp , $sp , -32
sw $31 , 28($sp)
sw $fp , 24($sp)
addu $fp , $sp , $0
addiu $2 , $0 , 0x1
sw $2 , 20($fp)
addiu $2 , $0 , 0xa
sw $2 , 16($fp)
addiu $2 , $0 , 0xa
sw $2 , 12($fp)
addiu $2 , $0 , 0xa
sw $2 , 8($fp)
addiu $2 , $0 , 0xa
sw $2 , 4($fp)
addiu $2 , $0 , 0xa
sw $2 , 0($fp)
lw $2 , 20($fp)
lw $3 , 16($fp)
addu $2 , $2 , $3
lw $3 , 12($fp)
addu $2 , $2 , $3
lw $3 , 8($fp)
addu $2 , $2 , $3
lw $3 , 4($fp)
addu $2 , $2 , $3
lw $3 , 0($fp)
addu $2 , $2 , $3
addu $2 , $2 , $0
andi $2 , $2 , 0x00ff
b $E0
nop
$E0:
addu $sp , $fp , $0
lw $fp , 24($sp)
sw $31 , 28($sp)
addiu $sp , $sp , 32
j $31
nop
.end arr

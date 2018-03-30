.globl random
.ent random
.type random, @function
random:
addiu $sp , $sp , -16
sw $31 , 12($sp)
sw $fp , 8($sp)
move $fp , $sp
addiu $2 , $0 , 0x5
sw $2 , 0($fp)
lw $2 , 0($fp)
addiu $3 , $0 , 0x0
addu $2 , $2 , $3
sw $2 , 0($fp)
lw $2 , 0($fp)
addiu $3 , $0 , 0x3
addiu $8 , $0 , 0x2
teq $8,$0,7
div $3 , $8
mflo $3
subu $2 , $2 , $3
sw $2 , 0($fp)
lw $2 , 0($fp)
addiu $3 , $0 , 0x4
teq $3,$0,7
div $2 , $3
mflo $2
sw $2 , 0($fp)
lw $2 , 0($fp)
addiu $3 , $0 , 0x1
subu $2 , $2 , $3
sw $2 , 4($fp)
lw $2 , 4($fp)
addu $2 , $2 , $0
b $E0
nop
$E0:
addu $sp , $fp , $0
lw $fp , 8($sp)
lw $31 , 12($sp)
addiu $sp , $sp , 16
j $31
nop
.end random

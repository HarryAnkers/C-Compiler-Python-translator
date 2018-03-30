.globl random
.ent random
.type random, @function
random:
addiu $sp , $sp , -32
sw $31 , 28($sp)
sw $fp , 24($sp)
move $fp , $sp
addiu $2 , $0 , 0x5
sw $2 , 8($fp)
lw $2 , 8($fp)
addiu $3 , $0 , 0x0
addu $2 , $2 , $3
sw $2 , 8($fp)
lw $2 , 8($fp)
addiu $3 , $0 , 0x3
addiu $8 , $0 , 0x2
teq $8,$0,7
div $3 , $8
mflo $3
subu $2 , $2 , $3
sw $2 , 8($fp)
lw $2 , 8($fp)
addiu $3 , $0 , 0x4
teq $3,$0,7
div $2 , $3
mflo $2
sw $2 , 8($fp)
lw $2 , 8($fp)
addiu $3 , $0 , 0x1
subu $2 , $2 , $3
sw $2 , 16($fp)
addiu $2 , $0 , 0x0
sw $2 , 20($fp)
$L1:
lw $2 , 20($fp)
addiu $3 , $0 , 0x5
slt $2 , $2 , $3
beq $2 , $0 , $L2
nop
lw $2 , 16($fp)
addiu $3 , $0 , 0x1
addu $2 , $2 , $3
sw $2 , 16($fp)
addiu $2 , $0 , 0x5
lw $3 , 16($fp)
subu $2 , $2 , $3
sw $2 , 8($fp)
lw $2 , 20($fp)
addiu $3 , $0 , 0x1
addu $2 , $2 , $3
sw $2 , 20($fp)
b $L1
nop
$L2:
lw $3 , 8($fp)
addu $2 , $3 , $0
b $E0
nop
$E0:
addu $sp , $fp , $0
lw $fp , 24($sp)
lw $31 , 28($sp)
addiu $sp , $sp , 32
j $31
nop
.end random

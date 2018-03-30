.globl random
.ent random
.type random, @function
random:
addiu $sp , $sp , -8
sw $31 , 4($sp)
sw $fp , 0($sp)
move $fp , $sp
sw $4 , 8($fp)
sw $5 , 12($fp)
addiu $2 , $0 , 0x5
sw $2 , 8($fp)
$L1:
lw $2 , 8($fp)
addiu $3 , $0 , 0x0
xor $2 , $2 , $3
sltu $2 , $0 , $2
beq $2 , $0 , $L2
nop
lw $2 , 8($fp)
addiu $3 , $0 , 0x1
subu $2 , $2 , $3
sw $2 , 8($fp)
lw $2 , 8($fp)
sw $2 , 12($fp)
b $L1
nop
$L2:
lw $2 , 8($fp)
addiu $3 , $0 , 0x0
xor $2 , $2 , $3
sltu $2 , $2 , 1
beq $2 , $0 , $L3
nop
lw $2 , 12($fp)
addu $2 , $2 , $0
b $E0
nop
$L3:
addiu $2 , $0 , 0x3
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
.end random

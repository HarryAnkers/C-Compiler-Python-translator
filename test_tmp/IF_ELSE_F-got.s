.globl iff
.ent iff
.type iff, @function
iff:
addiu $sp , $sp , -8
sw $31 , 4($sp)
sw $fp , 0($sp)
move $fp , $sp
sw $4 , 8($fp)
lw $2 , 8($fp)
addiu $3 , $0 , 0x1
xor $2 , $2 , $3
sltu $2 , $0 , $2
beq $2 , $0 , $L1
nop
addiu $2 , $0 , 0x2
addu $2 , $2 , $0
b $E0
nop
b $L2
nop
$L1:
addiu $2 , $0 , 0x0
addu $2 , $2 , $0
b $E0
nop
$L2:
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
.end iff

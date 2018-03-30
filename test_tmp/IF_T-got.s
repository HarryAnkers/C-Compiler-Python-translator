.globl IF_T
.ent IF_T
.type IF_T, @function
IF_T:
.frame $fp,8, $ra
.mask 0x40000000, -4
.fmask 0x00000000, 0
addiu $sp , $sp , -8
sw $31 , 4($sp)
sw $fp , 0($sp)
addu $fp , $sp , $0
sw $4 , 8($fp)
lw $2 , 8($fp)
sltu $2 , $2 , 1
sltu $2 , $2 , 1
beq $2 , $0 , $L1
nop
addiu $2 , $0 , 0x0
addu $2 , $2 , $0
andi $2 , $2 , 0x00ff
b $E0
nop
$L1:
addiu $2 , $0 , 0x2b
addu $2 , $2 , $0
andi $2 , $2 , 0x00ff
b $E0
nop
$E0:
addu $sp , $fp , $0
lw $fp , 0($sp)
sw $31 , 4($sp)
addiu $sp , $sp , 8
j $31
nop
.end IF_T

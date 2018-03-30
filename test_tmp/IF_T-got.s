.global IF_T
.ent IF_T
.type IF_T, @function
IF_T:
addiu $sp , $sp , -8
sw $31 , 4($sp)
sw $fp , 0($sp)
addu $fp , $sp , $0
sw $4 , 8($fp)
x
lw $2 , 8($fp)
beq $2 , $0 , $L1
nop
addiu $2 , $0 , 0x0
b $L2
nop

$L1:
addiu $2 , $0 , 0x1

$L2:
beq $2 , $0 , $L3
nop
addiu $2 , $0 , 0x0
b $L4
nop

$L3:
addiu $2 , $0 , 0x1

$L4:
beq $2 , $0 , $L5
nop
addiu $2 , $0 , 0x0
addu $2 , $2 , $0
b $E0
nop
$L5:
addiu $2 , $0 , 0x2b
addu $2 , $2 , $0
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

.global FOR_N
.ent FOR_N
.type FOR_N, @function
FOR_N:
addiu $sp , $sp , -16
sw $31 , 12($sp)
sw $fp , 8($sp)
addu $fp , $sp , $0
addiu $2 , $0 , 0xa
sw $2 , 0($fp)
addiu $2 , $0 , 0x0
sw $2 , 4($fp)
addiu $2 , $0 , 0x0
sw $2 , 0($fp)
$L1:
lw $2 , 0($fp)
addiu $3 , $0 , 0x32
slt $2 , $3 , $2
beq $2 , $0 , $L3
nop
addiu $2 , $0 , 0x1
b $L4
nop

$L3:
addiu $2 , $0 , 0x0
$L4:
beq $2 , $0 , $L2
nop
lw $2 , 4($fp)
addiu $3 , $0 , 0x1
addu $2 , $2 , $3
sw $2 , 4($fp)
lw $2 , 0($fp)
addiu $3 , $0 , 0x1
addu $2 , $2 , $3
sw $2 , 0($fp)
b $L1
nop
$L2:
addiu $3 , $0 , 0x45
addu $2 , $3 , $0
b $E0
nop
$E0:
addu $sp , $fp , $0
lw $fp , 8($sp)
sw $31 , 12($sp)
addiu $sp , $sp , 16
j $31
nop
.end FOR_N

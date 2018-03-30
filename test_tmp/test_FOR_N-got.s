.global func
.ent func
.type func, @function
func:
addiu $sp , $sp , -16
sw $31 , 12($sp)
sw $fp , 8($sp)
addu $fp , $sp , $0
addiu $2 , $0 , 0x5
sw $2 , 4($fp)
$L1:
lw $2 , 4($fp)
addiu $8 , $0 , 0x1
addiu $8 , $0 , 0xFFFF
sll $8 , $8 , 0xA
mult $8 , $8
mflo $3
slt $2 , $2 , $3
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
addiu $3 , $0 , 0x0
beq $2 , $3 , $L5
nop
addiu $2 , $0 , 0x0
b $L6
nop

$L5:
addiu $2 , $0 , 0x1
$L6:
beq $2 , $0 , $L7
nop
addiu $2 , $0 , 0x0
addu $2 , $2 , $0
b $E0
nop
$L7:
lw $2 , 4($fp)
addiu $3 , $0 , 0x1
subu $2 , $2 , $3
sw $2 , 4($fp)
b $L1
nop
$L2:
addiu $3 , $0 , 0x2
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
.end func

.globl func
.ent func
.type func, @function
func:
addiu $sp , $sp , -16
sw $31 , 12($sp)
sw $fp , 8($sp)
addu $fp , $sp , $0
addiu $2 , $0 , 0x1
sw $2 , 0($fp)
addiu $2 , $0 , 0x0
sw $2 , 4($fp)
lw $2 , 0($fp)
lw $3 , 0($fp)
beq $2 , $0 , $L1
nop
beq $3 , $0 , $L1
nop
addiu $2 , $0 , 0x1
b $L2
nop

$L1:
addiu $2 , $0 , 0x0

$L2:
beq $2 , $0 , $L3
nop
lw $2 , 0($fp)
lw $3 , 4($fp)
beq $2 , $0 , $L3
nop
beq $3 , $0 , $L3
nop
addiu $2 , $0 , 0x1
b $L4
nop

$L3:
addiu $2 , $0 , 0x0

$L4:
beq $2 , $0 , $L5
nop
addiu $2 , $0 , 0x1
addu $2 , $2 , $0
andi $2 , $2 , 0x00ff
b $E0
nop
b $L6
nop
$L5:
lw $2 , 4($fp)
lw $3 , 4($fp)
beq $2 , $0 , $L6
nop
beq $3 , $0 , $L6
nop
addiu $2 , $0 , 0x1
b $L7
nop

$L6:
addiu $2 , $0 , 0x0

$L7:
beq $2 , $0 , $L8
nop
addiu $2 , $0 , 0x2
addu $2 , $2 , $0
andi $2 , $2 , 0x00ff
b $E0
nop
b $L9
nop
$L8:
addiu $2 , $0 , 0xa
addu $2 , $2 , $0
andi $2 , $2 , 0x00ff
b $E0
nop
$L9:
$L10:
$L11:
addiu $2 , $0 , 0x14
addu $2 , $2 , $0
andi $2 , $2 , 0x00ff
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

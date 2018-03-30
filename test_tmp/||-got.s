.global func
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
bne $2 , $0 , $L1
nop
bne $3 , $0 , $L1
nop
addiu $2 , $0 , 0x0
b $L2
nop

$L1:
addiu $2 , $0 , 0x1

$L2:
beq $2 , $0 , $L3
nop
lw $2 , 0($fp)
lw $3 , 4($fp)
bne $2 , $0 , $L3
nop
bne $3 , $0 , $L3
nop
addiu $2 , $0 , 0x0
b $L4
nop

$L3:
addiu $2 , $0 , 0x1

$L4:
beq $2 , $0 , $L5
nop
lw $2 , 4($fp)
lw $3 , 0($fp)
bne $2 , $0 , $L5
nop
bne $3 , $0 , $L5
nop
addiu $2 , $0 , 0x0
b $L6
nop

$L5:
addiu $2 , $0 , 0x1

$L6:
beq $2 , $0 , $L7
nop
lw $2 , 4($fp)
lw $3 , 4($fp)
bne $2 , $0 , $L7
nop
bne $3 , $0 , $L7
nop
addiu $2 , $0 , 0x0
b $L8
nop

$L7:
addiu $2 , $0 , 0x1

$L8:
beq $2 , $0 , $L9
nop
addiu $2 , $0 , 0x14
addu $2 , $2 , $0
andi $2 , $2 , 0x00ff
b $E0
nop
b $L10
nop
$L9:
addiu $2 , $0 , 0xa
addu $2 , $2 , $0
andi $2 , $2 , 0x00ff
b $E0
nop
$L10:
$L11:
$L12:
$L13:
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

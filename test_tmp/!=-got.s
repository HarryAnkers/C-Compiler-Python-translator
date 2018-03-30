.globl func
.ent func
.type func, @function
func:
.frame $fp,16, $ra
.mask 0x40000000, -4
.fmask 0x00000000, 0
addiu $sp , $sp , -16
sw $31 , 12($sp)
sw $fp , 8($sp)
addu $fp , $sp , $0
addiu $2 , $0 , 0x1
sw $2 , 0($fp)
addiu $2 , $0 , 0x0
sw $2 , 4($fp)
lw $2 , 0($fp)
lw $3 , 4($fp)
xor $2 , $2 , $3
sltu $2 , $0 , $2
beq $2 , $0 , $L1
nop
lw $2 , 0($fp)
lw $3 , 0($fp)
xor $2 , $2 , $3
sltu $2 , $0 , $2
beq $2 , $0 , $L1
nop
addiu $2 , $0 , 0x1
addu $2 , $2 , $0
andi $2 , $2 , 0x00ff
b $E0
nop
b $L2
nop
$L1:
lw $2 , 4($fp)
lw $3 , 4($fp)
xor $2 , $2 , $3
sltu $2 , $0 , $2
beq $2 , $0 , $L2
nop
addiu $2 , $0 , 0x2
addu $2 , $2 , $0
andi $2 , $2 , 0x00ff
b $E0
nop
b $L3
nop
$L2:
addiu $2 , $0 , 0xa
addu $2 , $2 , $0
andi $2 , $2 , 0x00ff
b $E0
nop
$L3:
$L4:
$L5:
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

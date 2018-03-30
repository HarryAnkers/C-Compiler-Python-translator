.globl f
.ent f
.type f, @function
f:
.frame $fp,8, $ra
.mask 0x40000000, -4
.fmask 0x00000000, 0
addiu $sp , $sp , -8
sw $31 , 4($sp)
sw $fp , 0($sp)
addu $fp , $sp , $0
addiu $2 , $0 , 0xa
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
.end f

.globl h
.ent h
.type h, @function
h:
.frame $fp,24, $ra
.mask 0x40000000, -4
.fmask 0x00000000, 0
addiu $sp , $sp , -24
sw $31 , 20($sp)
sw $fp , 16($sp)
addu $fp , $sp , $0
jal f
nop
addu $2 , $2 , $0

addu $2 , $2 , $0
andi $2 , $2 , 0x00ff
b $E1
nop
$E1:
addu $sp , $fp , $0
lw $fp , 16($sp)
sw $31 , 20($sp)
addiu $sp , $sp , 24
j $31
nop
.end h

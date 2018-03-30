.globl f
.ent f
.type f, @function
f:
addiu $sp , $sp , -8
sw $31 , 4($sp)
sw $fp , 0($sp)
move $fp , $sp
sw $4 , 8($fp)
sw $5 , 12($fp)
sw $6 , 16($fp)
sw $7 , 20($fp)
addiu $2 , $0 , 0xa
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
.end f

.globl h
.ent h
.type h, @function
h:
addiu $sp , $sp , -24
sw $31 , 20($sp)
sw $fp , 16($sp)
move $fp , $sp
addiu $2 , $0 , 0x1
addu $7 , $2 , $0
addiu $2 , $0 , 0x1
addu $6 , $2 , $0
addiu $2 , $0 , 0x1
addu $5 , $2 , $0
addiu $2 , $0 , 0x1
addu $4 , $2 , $0
jal f
nop
addu $2 , $2 , $0

addu $2 , $2 , $0
b $E1
nop
$E1:
addu $sp , $fp , $0
lw $fp , 16($sp)
lw $31 , 20($sp)
addiu $sp , $sp , 24
j $31
nop
.end h

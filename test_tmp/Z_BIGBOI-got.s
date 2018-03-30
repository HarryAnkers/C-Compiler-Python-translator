.globl function
.ent function
.type function, @function
function:
addiu $sp , $sp , -8
sw $31 , 4($sp)
sw $fp , 0($sp)
move $fp , $sp
sw $4 , 8($fp)
sw $5 , 12($fp)
lw $2 , 8($fp)
lw $3 , 12($fp)
slt $2 , $2 , $3
beq $2 , $0 , $L1
nop
lw $2 , 8($fp)
addiu $3 , $0 , 0x1
subu $2 , $2 , $3
sw $2 , 8($fp)
lw $2 , 8($fp)
lw $3 , 12($fp)
slt $2 , $2 , $3
beq $2 , $0 , $L1
nop
lw $2 , 12($fp)
addiu $3 , $0 , 0x3
addu $2 , $2 , $3
sw $2 , 12($fp)
lw $2 , 8($fp)
lw $3 , 12($fp)
xor $2 , $2 , $3
sltu $2 , $2 , 1
beq $2 , $0 , $L1
nop
lw $2 , 8($fp)
lw $3 , 12($fp)
mult $2 , $3
mflo $2
addu $2 , $2 , $0
b $E0
nop
$L1:
$L2:
lw $2 , 12($fp)
addu $2 , $2 , $0
b $E0
nop
$L3:
addiu $2 , $0 , 0xd
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
.end function

.globl z
.ent z
.type z, @function
z:
addiu $sp , $sp , -24
sw $31 , 20($sp)
sw $fp , 16($sp)
move $fp , $sp
addiu $2 , $0 , 0x0
addu $5 , $2 , $0
addiu $2 , $0 , 0x0
addu $4 , $2 , $0
jal function
nop
addu $2 , $2 , $0

addiu $3 , $0 , 0x2
addu $5 , $3 , $0
addiu $3 , $0 , 0x1
addu $4 , $3 , $0
jal function
nop
addu $3 , $2 , $0

addu $2 , $2 , $3
addiu $3 , $0 , 0x3
addu $5 , $3 , $0
addiu $3 , $0 , 0x4
addu $4 , $3 , $0
jal function
nop
addu $3 , $2 , $0

addu $2 , $2 , $3
addiu $3 , $0 , 0x7
addu $5 , $3 , $0
addiu $3 , $0 , 0x6
addu $4 , $3 , $0
jal function
nop
addu $3 , $2 , $0

addu $2 , $2 , $3
addu $2 , $2 , $0
b $E4
nop
$E4:
addu $sp , $fp , $0
lw $fp , 16($sp)
lw $31 , 20($sp)
addiu $sp , $sp , 24
j $31
nop
.end z

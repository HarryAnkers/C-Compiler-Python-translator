.globl function
.ent function
.type function, @function
function:
addiu $sp , $sp , -24
sw $31 , 20($sp)
sw $fp , 16($sp)
addu $fp , $sp , $0
sw $4 , 24($fp)
lw $2 , 24($fp)
addiu $3 , $0 , 0x0
xor $2 , $2 , $3
sltu $2 , $2 , 1
beq $2 , $0 , $L1
nop
lw $2 , 24($fp)
addu $2 , $2 , $0
andi $2 , $2 , 0x00ff
b $E0
nop
b $L2
nop
$L1:
lw $2 , 24($fp)
addiu $3 , $0 , 0x1
subu $2 , $2 , $3
sw $2 , 24($fp)
lw $2 , 24($fp)
addu $4 , $2 , $0
jal function
nop
addu $2 , $2 , $0

addu $2 , $2 , $0
andi $2 , $2 , 0x00ff
b $E0
nop
$L2:
$E0:
addu $sp , $fp , $0
lw $fp , 16($sp)
sw $31 , 20($sp)
addiu $sp , $sp , 24
j $31
nop
.end function

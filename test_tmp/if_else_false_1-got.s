.globl function
.ent function
.type function, @function
function:
addiu $sp , $sp , -8
sw $31 , 4($sp)
sw $fp , 0($sp)
move $fp , $sp
addiu $2 , $0 , 0x0
beq $2 , $0 , $L1
nop
addiu $2 , $0 , 0x1
addu $2 , $2 , $0
b $E0
nop
b $L2
nop
$L1:
addiu $2 , $0 , 0x0
addu $2 , $2 , $0
b $E0
nop
$L2:
$E0:
addu $sp , $fp , $0
lw $fp , 0($sp)
lw $31 , 4($sp)
addiu $sp , $sp , 8
j $31
nop
.end function

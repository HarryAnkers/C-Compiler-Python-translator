.globl function
.ent function
.type function, @function
function:
addiu $sp , $sp , -16
sw $31 , 12($sp)
sw $fp , 8($sp)
move $fp , $sp
addiu $2 , $0 , 0x1
sw $2 , 0($fp)
addiu $2 , $0 , 0x1
sw $2 , 4($fp)
lw $2 , 0($fp)
beq $2 , $0 , $L1
nop
addiu $2 , $0 , 0x0
sw $2 , 4($fp)
$L1:
lw $2 , 4($fp)
addu $2 , $2 , $0
b $E0
nop
$E0:
addu $sp , $fp , $0
lw $fp , 8($sp)
lw $31 , 12($sp)
addiu $sp , $sp , 16
j $31
nop
.end function

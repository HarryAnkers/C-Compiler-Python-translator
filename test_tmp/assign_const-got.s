.global assign
.ent assign
.type assign, @function

assign:
addiu $sp , $sp , -8
sw $31 , 4($sp)
sw $fp , 0($sp)
add $fp , $sp , $0
addi $2 , $0 , 0x1
addu $4 , $2 , $0
jal assign
nop
addu $2 , $2 , $0

add $2 , $2 , $0
b $E0
nop
$E0:
add $sp , $fp , $0
lw $fp , 8($sp)
sw $31 , 12($sp)
addiu $sp , $sp , 16
j $31
nop
.end assign


.global main
.ent main
.type main, @function

main:
addiu $sp , $sp , -16
sw $31 , 12($sp)
sw $fp , 8($sp)
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
.end main

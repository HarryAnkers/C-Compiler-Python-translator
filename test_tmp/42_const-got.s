.global blank
.ent blank
.type blank, @function

blank:
addiu $sp , $sp , -8
sw $31 , 4($sp)
sw $fp , 0($sp)
add $fp , $sp , $0
addi $2 , $0 , 0x2a
addu $2 , $2 , $0
b $E0
nop
$E0:
add $sp , $fp , $0
lw $fp , 0($sp)
sw $31 , 4($sp)
addiu $sp , $sp , 8
j $31
nop
.end blank

.global assign
.ent assign
.type assign, @function

assign:
addiu $sp , $sp , -8
sw $31 , 4($sp)
sw $fp , 0($sp)
add $fp , $sp , $0
addi $2 , $0 , 0x1
add $2 , $2 , $0
b $E0
E0:
add $sp , $fp , $0
lw $fp , 0($sp)
sw $31 , 4($sp)
addiu $sp , $sp , 8
j 31
nop

.end


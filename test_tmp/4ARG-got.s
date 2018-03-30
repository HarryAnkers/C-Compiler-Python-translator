.global arg4
.ent arg4
.type arg4, @function
arg4:
addiu $sp , $sp , -8
sw $31 , 4($sp)
sw $fp , 0($sp)
addu $fp , $sp , $0
sw $4 , 8($fp)
sw $5 , 12($fp)
sw $6 , 16($fp)
sw $7 , 20($fp)
lw $2 , 8($fp)
lw $3 , 12($fp)
addu $2 , $2 , $3
lw $3 , 16($fp)
addu $2 , $2 , $3
lw $3 , 20($fp)
addu $2 , $2 , $3
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
.end arg4

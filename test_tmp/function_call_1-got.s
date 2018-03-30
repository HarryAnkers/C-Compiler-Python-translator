.globl function1
.ent function1
.type function1, @function
function1:
addiu $sp , $sp , -8
sw $31 , 4($sp)
sw $fp , 0($sp)
addu $fp , $sp , $0
addiu $2 , $0 , 0x0
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
.end function1

.globl function2
.ent function2
.type function2, @function
function2:
addiu $sp , $sp , -24
sw $31 , 20($sp)
sw $fp , 16($sp)
addu $fp , $sp , $0
jal function1
nop
addu $2 , $2 , $0

addu $2 , $2 , $0
andi $2 , $2 , 0x00ff
b $E1
nop
$E1:
addu $sp , $fp , $0
lw $fp , 16($sp)
sw $31 , 20($sp)
addiu $sp , $sp , 24
j $31
nop
.end function2

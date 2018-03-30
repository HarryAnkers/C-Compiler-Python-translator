.global func
.ent func
.type func, @function
func:
addiu $sp , $sp , -16
sw $31 , 12($sp)
sw $fp , 8($sp)
addu $fp , $sp , $0
addiu $2 , $0 , 0x1
sw $2 , 0($fp)
addiu $2 , $0 , 0x0
sw $2 , 4($fp)
lw $2 , 0($fp)
lw $3 , 4($fp)
xor $2 , $2 , $3
sltu $2 , $2 , 1
beq $2 , $0 , $L1
nop
addiu $2 , $0 , 0x5
addu $2 , $2 , $0
andi $2 , $2 , 0x00ff
b $E0
nop
b $L2
nop
$L1:
lw $2 , 0($fp)
lw $3 , 0($fp)
xor $2 , $2 , $3
sltu $2 , $2 , 1
beq $2 , $0 , $L2
nop
lw $2 , 4($fp)
lw $3 , 4($fp)
xor $2 , $2 , $3
sltu $2 , $2 , 1
beq $2 , $0 , $L2
nop
addiu $2 , $0 , 0xa
addu $2 , $2 , $0
andi $2 , $2 , 0x00ff
b $E0
nop
$L2:
$L3:
$L4:
addiu $2 , $0 , 0x14
addu $2 , $2 , $0
andi $2 , $2 , 0x00ff
b $E0
nop
$E0:
addu $sp , $fp , $0
lw $fp , 8($sp)
sw $31 , 12($sp)
addiu $sp , $sp , 16
j $31
nop
.end func

.global self
.ent self
.type self, @function
self:
addiu $sp , $sp , -16
sw $31 , 12($sp)
sw $fp , 8($sp)
addu $fp , $sp , $0
sw $4 , 16($fp)
lw $2 , 16($fp)
addiu $3 , $0 , 0x0
slt $2 , $3 , $2
beq $2 , $0 , $L1
nop
lw $2 , 16($fp)
addiu $3 , $0 , 0x1
subu $2 , $2 , $3
sw $2 , 16($fp)
lw $2 , 16($fp)
addu $4 , $2 , $0
jal self
nop
addu $2 , $2 , $0

addu $2 , $2 , $0
andi $2 , $2 , 0x00ff
b $E0
nop
b $L2
nop
$L1:
lw $2 , 16($fp)
addu $2 , $2 , $0
andi $2 , $2 , 0x00ff
b $E0
nop
$L2:
$E0:
addu $sp , $fp , $0
lw $fp , 8($sp)
sw $31 , 12($sp)
addiu $sp , $sp , 16
j $31
nop
.end self

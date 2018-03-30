.global FOR_N
.ent FOR_N
.type FOR_N, @function
FOR_N:
addiu $sp , $sp , -8
sw $31 , 4($sp)
sw $fp , 0($sp)
addu $fp , $sp , $0
sw $4 , 8($fp)
sw $5 , 12($fp)
sw $6 , 16($fp)
sw $7 , 20($fp)
f
e
d
c
b
a

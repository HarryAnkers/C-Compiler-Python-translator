.global glob
.ent glob
.type glob, @function
glob:
addiu $sp , $sp , -8
sw $31 , 4($sp)
sw $fp , 0($sp)
addu $fp , $sp , $0

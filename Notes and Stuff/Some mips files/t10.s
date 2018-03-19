main:
	.frame	$fp,16,$31		# vars= 8, regs= 1/0, args= 0, gp= 0
	.mask	0x40000000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	addiu	$sp,$sp,-16
	sw	$fp,12($sp)
	move	$fp,$sp
	sw	$4,16($fp)
	sw	$5,20($fp)
	li	$2,1			# 0x1
	sw	$2,16($fp)
	li	$2,2			# 0x2
	sw	$2,20($fp)
	li	$2,3			# 0x3
	sw	$2,0($fp)
	li	$2,4			# 0x4
	sw	$2,4($fp)
	lw	$3,16($fp)
	lw	$2,20($fp)
	addu	$3,$3,$2
	lw	$2,0($fp)
	addu	$3,$3,$2
	lw	$2,4($fp)
	addu	$2,$3,$2
	move	$sp,$fp
	lw	$fp,12($sp)
	addiu	$sp,$sp,16
	j	$31
	nop

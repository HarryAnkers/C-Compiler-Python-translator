main:
	.frame	$fp,40,$31		# vars= 32, regs= 1/0, args= 0, gp= 0
	.mask	0x40000000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	addiu	$sp,$sp,-40
	sw	$fp,36($sp)
	move	$fp,$sp
	li	$2,1			# 0x1
	sw	$2,4($fp)
	li	$2,2			# 0x2
	sw	$2,8($fp)
	li	$2,3			# 0x3
	sw	$2,12($fp)
	li	$2,4			# 0x4
	sw	$2,16($fp)
	li	$2,5			# 0x5
	sw	$2,20($fp)
	li	$2,6			# 0x6
	sw	$2,24($fp)
	li	$2,7			# 0x7
	sw	$2,28($fp)
	lw	$3,4($fp)
	lw	$2,8($fp)
	addu	$3,$3,$2
	lw	$2,12($fp)
	addu	$3,$3,$2
	lw	$2,16($fp)
	addu	$3,$3,$2
	lw	$2,20($fp)
	addu	$3,$3,$2
	lw	$2,24($fp)
	addu	$3,$3,$2
	lw	$2,28($fp)
	addu	$2,$3,$2
	move	$sp,$fp
	lw	$fp,36($sp)
	addiu	$sp,$sp,40
	j	$31
	nop

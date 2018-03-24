	.file	1 "t28.c"
	.section .mdebug.abi32
	.previous
	.nan	legacy
	.module	fp=xx
	.module	nooddspreg
	.abicalls
	.text
	.align	2
	.globl	f2
	.set	nomips16
	.set	nomicromips
	.ent	f2
	.type	f2, @function
f2:
	.frame	$fp,8,$31		# vars= 0, regs= 1/0, args= 0, gp= 0
	.mask	0x40000000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	addiu	$sp,$sp,-8
	sw	$fp,4($sp)
	move	$fp,$sp
	sw	$4,8($fp)
	sw	$5,12($fp)
	sw	$6,16($fp)
	sw	$7,20($fp)
	nop
	move	$sp,$fp
	lw	$fp,4($sp)
	addiu	$sp,$sp,8
	j	$31
	nop

	.set	macro
	.set	reorder
	.end	f2
	.size	f2, .-f2
	.align	2
	.globl	f1
	.set	nomips16
	.set	nomicromips
	.ent	f1
	.type	f1, @function
f1:
	.frame	$fp,56,$31		# vars= 16, regs= 2/0, args= 24, gp= 8
	.mask	0xc0000000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	addiu	$sp,$sp,-56
	sw	$31,52($sp)
	sw	$fp,48($sp)
	move	$fp,$sp
	li	$2,1			# 0x1
	sw	$2,32($fp)
	li	$2,2			# 0x2
	sw	$2,36($fp)
	li	$2,3			# 0x3
	sw	$2,40($fp)
	li	$2,4			# 0x4
	sw	$2,44($fp)
	li	$2,6			# 0x6
	sw	$2,20($sp)
	li	$2,5			# 0x5
	sw	$2,16($sp)
	li	$7,4			# 0x4
	li	$6,3			# 0x3
	li	$5,2			# 0x2
	li	$4,1			# 0x1
	.option	pic0
	jal	f2
	nop

	.option	pic2
	lw	$3,32($fp)
	lw	$2,36($fp)
	addu	$3,$3,$2
	lw	$2,40($fp)
	addu	$2,$3,$2
	move	$sp,$fp
	lw	$31,52($sp)
	lw	$fp,48($sp)
	addiu	$sp,$sp,56
	j	$31
	nop

	.set	macro
	.set	reorder
	.end	f1
	.size	f1, .-f1
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.9) 5.4.0 20160609"

	.file	1 "t26.c"
	.section .mdebug.abi32
	.previous
	.nan	legacy
	.module	fp=xx
	.module	nooddspreg
	.abicalls
	.text
	.align	2
	.globl	f
	.set	nomips16
	.set	nomicromips
	.ent	f
	.type	f, @function
f:
	.frame	$fp,8,$31		# vars= 0, regs= 1/0, args= 0, gp= 0
	.mask	0x40000000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	addiu	$sp,$sp,-8
	sw	$fp,4($sp)
	move	$fp,$sp
	nop
	move	$sp,$fp
	lw	$fp,4($sp)
	addiu	$sp,$sp,8
	j	$31
	nop

	.set	macro
	.set	reorder
	.end	f
	.size	f, .-f
	.align	2
	.globl	f1
	.set	nomips16
	.set	nomicromips
	.ent	f1
	.type	f1, @function
f1:
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
	lw	$3,8($fp)
	lw	$2,12($fp)
	addu	$3,$3,$2
	lw	$2,16($fp)
	addu	$3,$3,$2
	lw	$2,20($fp)
	addu	$2,$3,$2
	move	$sp,$fp
	lw	$fp,4($sp)
	addiu	$sp,$sp,8
	j	$31
	nop

	.set	macro
	.set	reorder
	.end	f1
	.size	f1, .-f1
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
	lw	$3,8($fp)
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
	lw	$fp,4($sp)
	addiu	$sp,$sp,8
	j	$31
	nop

	.set	macro
	.set	reorder
	.end	f2
	.size	f2, .-f2
	.align	2
	.globl	f3
	.set	nomips16
	.set	nomicromips
	.ent	f3
	.type	f3, @function
f3:
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
	lw	$3,8($fp)
	lw	$2,12($fp)
	addu	$3,$3,$2
	lw	$2,16($fp)
	addu	$3,$3,$2
	lw	$2,20($fp)
	addu	$3,$3,$2
	lw	$2,24($fp)
	addu	$3,$3,$2
	lw	$2,28($fp)
	addu	$3,$3,$2
	lw	$2,32($fp)
	addu	$3,$3,$2
	lw	$2,36($fp)
	addu	$2,$3,$2
	move	$sp,$fp
	lw	$fp,4($sp)
	addiu	$sp,$sp,8
	j	$31
	nop

	.set	macro
	.set	reorder
	.end	f3
	.size	f3, .-f3
	.align	2
	.globl	f4
	.set	nomips16
	.set	nomicromips
	.ent	f4
	.type	f4, @function
f4:
	.frame	$fp,64,$31		# vars= 16, regs= 2/0, args= 32, gp= 8
	.mask	0xc0000000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	addiu	$sp,$sp,-64
	sw	$31,60($sp)
	sw	$fp,56($sp)
	move	$fp,$sp
	.option	pic0
	jal	f
	nop

	.option	pic2
	li	$2,66			# 0x42
	sw	$2,44($fp)
	li	$2,77			# 0x4d
	sw	$2,48($fp)
	li	$2,88			# 0x58
	sw	$2,52($fp)
	li	$7,4			# 0x4
	li	$6,3			# 0x3
	li	$5,2			# 0x2
	li	$4,1			# 0x1
	.option	pic0
	jal	f1
	nop

	.option	pic2
	sw	$2,44($fp)
	li	$2,10			# 0xa
	sw	$2,20($sp)
	li	$2,9			# 0x9
	sw	$2,16($sp)
	li	$7,8			# 0x8
	li	$6,7			# 0x7
	li	$5,6			# 0x6
	li	$4,5			# 0x5
	.option	pic0
	jal	f2
	nop

	.option	pic2
	sw	$2,48($fp)
	li	$2,18			# 0x12
	sw	$2,28($sp)
	li	$2,17			# 0x11
	sw	$2,24($sp)
	li	$2,16			# 0x10
	sw	$2,20($sp)
	li	$2,15			# 0xf
	sw	$2,16($sp)
	li	$7,14			# 0xe
	li	$6,13			# 0xd
	li	$5,12			# 0xc
	li	$4,11			# 0xb
	.option	pic0
	jal	f3
	nop

	.option	pic2
	sw	$2,52($fp)
	lw	$3,44($fp)
	lw	$2,48($fp)
	addu	$3,$3,$2
	lw	$2,52($fp)
	addu	$2,$3,$2
	move	$sp,$fp
	lw	$31,60($sp)
	lw	$fp,56($sp)
	addiu	$sp,$sp,64
	j	$31
	nop

	.set	macro
	.set	reorder
	.end	f4
	.size	f4, .-f4
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.9) 5.4.0 20160609"

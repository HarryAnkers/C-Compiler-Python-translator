	.file	1 "t35.c"
	.section .mdebug.abi32
	.previous
	.nan	legacy
	.module	fp=xx
	.module	nooddspreg
	.abicalls
	.text
	.align	2
	.globl	main
	.set	nomips16
	.set	nomicromips
	.ent	main
	.type	main, @function
main:
	.frame	$fp,40,$31		# vars= 32, regs= 1/0, args= 0, gp= 0
	.mask	0x40000000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	addiu	$sp,$sp,-40
	sw	$fp,36($sp)
	move	$fp,$sp
	sw	$4,40($fp)
	li	$2,3			# 0x3
	sw	$2,12($fp)
	li	$2,6			# 0x6
	sw	$2,16($fp)
	li	$2,2			# 0x2
	sw	$2,20($fp)
	li	$2,4			# 0x4
	sw	$2,24($fp)
	lw	$2,40($fp)
	beq	$2,$0,$L2
	nop

	lw	$3,12($fp)
	lw	$2,16($fp)
	addu	$2,$3,$2
	sw	$2,4($fp)
$L2:
	lw	$2,40($fp)
	beq	$2,$0,$L3
	nop

	lw	$3,12($fp)
	lw	$2,16($fp)
	addu	$2,$3,$2
	sw	$2,8($fp)
$L3:
	lw	$2,40($fp)
	beq	$2,$0,$L4
	nop

	lw	$3,12($fp)
	lw	$2,20($fp)
	addu	$2,$3,$2
	sw	$2,4($fp)
$L4:
	lw	$2,40($fp)
	beq	$2,$0,$L5
	nop

	lw	$3,12($fp)
	lw	$2,20($fp)
	addu	$2,$3,$2
	sw	$2,8($fp)
$L5:
	lw	$2,40($fp)
	beq	$2,$0,$L6
	nop

	lw	$3,12($fp)
	lw	$2,20($fp)
	addu	$2,$3,$2
	sw	$2,4($fp)
$L6:
	lw	$2,40($fp)
	beq	$2,$0,$L7
	nop

	lw	$2,12($fp)
	lw	$3,20($fp)
	addu	$2,$3,$2
	sw	$2,8($fp)
$L7:
	lw	$2,40($fp)
	beq	$2,$0,$L8
	nop

	lw	$3,20($fp)
	lw	$2,24($fp)
	addu	$2,$3,$2
	sw	$2,4($fp)
$L8:
	lw	$2,40($fp)
	beq	$2,$0,$L9
	nop

	lw	$3,20($fp)
	lw	$2,24($fp)
	addu	$2,$3,$2
	sw	$2,8($fp)
$L9:
	li	$2,3			# 0x3
	sw	$2,28($fp)
	lw	$3,4($fp)
	lw	$2,8($fp)
	addu	$2,$3,$2
	move	$sp,$fp
	lw	$fp,36($sp)
	addiu	$sp,$sp,40
	j	$31
	nop

	.set	macro
	.set	reorder
	.end	main
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.9) 5.4.0 20160609"

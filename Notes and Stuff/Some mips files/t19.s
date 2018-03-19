	.file	1 "t19.c"
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
	lw	$2,8($fp)
	beq	$2,$0,$L2
	nop

	lw	$2,12($fp)
	beq	$2,$0,$L3
	nop

	lw	$2,20($fp)
	addiu	$2,$2,10
	sw	$2,20($fp)
	b	$L2
	nop

$L3:
	lw	$2,16($fp)
	beq	$2,$0,$L2
	nop

	lw	$2,20($fp)
	addiu	$2,$2,40
	sw	$2,20($fp)
$L2:
	li	$2,40			# 0x28
	move	$sp,$fp
	lw	$fp,4($sp)
	addiu	$sp,$sp,8
	j	$31
	nop

	.set	macro
	.set	reorder
	.end	main
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.9) 5.4.0 20160609"

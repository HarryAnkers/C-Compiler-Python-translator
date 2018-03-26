	.file	1 "t34.c"
	.section .mdebug.abi32
	.previous
	.nan	legacy
	.module	fp=xx
	.module	nooddspreg
	.abicalls
	.globl	a
	.data
	.align	2
	.type	a, @object
	.size	a, 4
a:
	.word	23
	.text
	.align	2
	.globl	main
	.set	nomips16
	.set	nomicromips
	.ent	main
	.type	main, @function
main:
	.frame	$fp,16,$31		# vars= 8, regs= 1/0, args= 0, gp= 0
	.mask	0x40000000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	addiu	$sp,$sp,-16
	sw	$fp,12($sp)
	move	$fp,$sp
	lui	$2,%hi(a)
	lw	$2,%lo(a)($2)
	addiu	$3,$2,66
	lui	$2,%hi(a)
	sw	$3,%lo(a)($2)
	li	$2,2			# 0x2
	sw	$2,4($fp)
	lui	$2,%hi(a)
	lw	$3,%lo(a)($2)
	lw	$2,4($fp)
	addu	$2,$3,$2
	move	$sp,$fp
	lw	$fp,12($sp)
	addiu	$sp,$sp,16
	j	$31
	nop

	.set	macro
	.set	reorder
	.end	main
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.9) 5.4.0 20160609"

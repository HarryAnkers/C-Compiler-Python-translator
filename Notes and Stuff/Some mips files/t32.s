	.file	1 "t32.c"
	.section .mdebug.abi32
	.previous
	.nan	legacy
	.module	fp=xx
	.module	nooddspreg
	.abicalls
	.globl	i
	.data
	.align	2
	.type	i, @object
	.size	i, 4
i:
	.word	13
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
	lui	$2,%hi(i)
	li	$3,53434			# 0xd0ba
	sw	$3,%lo(i)($2)
	lui	$2,%hi(i)
	lw	$2,%lo(i)($2)
	move	$sp,$fp
	lw	$fp,4($sp)
	addiu	$sp,$sp,8
	j	$31
	nop

	.set	macro
	.set	reorder
	.end	f2
	.size	f2, .-f2
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.9) 5.4.0 20160609"

	.file	1 "t13.c"
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

	li	$2,1111			# 0x457
	b	$L3
	nop

$L2:
	lw	$2,12($fp)
	beq	$2,$0,$L4
	nop

	li	$2,2222			# 0x8ae
	b	$L3
	nop

$L4:
	lw	$2,16($fp)
	beq	$2,$0,$L5
	nop

	li	$2,3333			# 0xd05
	b	$L3
	nop

$L5:
	lw	$2,20($fp)
	beq	$2,$0,$L6
	nop

	li	$2,4444			# 0x115c
	b	$L3
	nop

$L6:
	li	$2,5555			# 0x15b3
$L3:
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

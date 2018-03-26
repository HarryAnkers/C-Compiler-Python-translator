	.file	1 "t37.c"
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
	.frame	$fp,32,$31		# vars= 24, regs= 1/0, args= 0, gp= 0
	.mask	0x40000000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	addiu	$sp,$sp,-32
	sw	$fp,28($sp)
	move	$fp,$sp
	sw	$4,32($fp)
	li	$2,-3			# 0xfffffffffffffffd
	sw	$2,0($fp)
	li	$2,-6			# 0xfffffffffffffffa
	sw	$2,4($fp)
	li	$2,2			# 0x2
	sw	$2,8($fp)
	li	$2,4			# 0x4
	sw	$2,12($fp)
	lw	$2,0($fp)
	bne	$2,$0,$L2
	nop

	lw	$2,4($fp)
	beq	$2,$0,$L3
	nop

$L2:
	li	$2,1			# 0x1
	b	$L4
	nop

$L3:
	move	$2,$0
$L4:
	sw	$2,16($fp)
	lw	$2,0($fp)
	bne	$2,$0,$L5
	nop

	lw	$2,4($fp)
	beq	$2,$0,$L6
	nop

$L5:
	li	$2,1			# 0x1
	b	$L7
	nop

$L6:
	move	$2,$0
$L7:
	sw	$2,20($fp)
	lw	$2,8($fp)
	bne	$2,$0,$L8
	nop

	lw	$2,12($fp)
	beq	$2,$0,$L9
	nop

$L8:
	li	$2,1			# 0x1
	b	$L10
	nop

$L9:
	move	$2,$0
$L10:
	sw	$2,16($fp)
	lw	$2,8($fp)
	bne	$2,$0,$L11
	nop

	lw	$2,12($fp)
	beq	$2,$0,$L12
	nop

$L11:
	li	$2,1			# 0x1
	b	$L13
	nop

$L12:
	move	$2,$0
$L13:
	sw	$2,20($fp)
	lw	$3,16($fp)
	lw	$2,20($fp)
	addu	$2,$3,$2
	move	$sp,$fp
	lw	$fp,28($sp)
	addiu	$sp,$sp,32
	j	$31
	nop

	.set	macro
	.set	reorder
	.end	main
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.9) 5.4.0 20160609"

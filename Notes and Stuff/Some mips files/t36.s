	.file	1 "t36.c"
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
	lw	$3,0($fp)
	lw	$2,4($fp)
	sra	$2,$3,$2
	sw	$2,16($fp)
	lw	$3,0($fp)
	lw	$2,4($fp)
	sra	$2,$3,$2
	sw	$2,20($fp)
	lw	$3,0($fp)
	lw	$2,4($fp)
	teq	$2,$0,7
	div	$0,$3,$2
	mfhi	$2
	mflo	$2
	sw	$2,16($fp)
	lw	$3,0($fp)
	lw	$2,4($fp)
	teq	$2,$0,7
	div	$0,$3,$2
	mfhi	$2
	mflo	$2
	sw	$2,20($fp)
	lw	$3,0($fp)
	lw	$2,4($fp)
	teq	$2,$0,7
	div	$0,$3,$2
	mfhi	$2
	sw	$2,16($fp)
	lw	$3,0($fp)
	lw	$2,4($fp)
	teq	$2,$0,7
	div	$0,$3,$2
	mfhi	$2
	sw	$2,20($fp)
	lw	$2,0($fp)
	beq	$2,$0,$L2
	nop

	lw	$2,4($fp)
	beq	$2,$0,$L2
	nop

	li	$2,1			# 0x1
	b	$L3
	nop

$L2:
	move	$2,$0
$L3:
	sw	$2,16($fp)
	lw	$2,0($fp)
	beq	$2,$0,$L4
	nop

	lw	$2,4($fp)
	beq	$2,$0,$L4
	nop

	li	$2,1			# 0x1
	b	$L5
	nop

$L4:
	move	$2,$0
$L5:
	sw	$2,20($fp)
	lw	$2,0($fp)
	bne	$2,$0,$L6
	nop

	lw	$2,4($fp)
	beq	$2,$0,$L7
	nop

$L6:
	li	$2,1			# 0x1
	b	$L8
	nop

$L7:
	move	$2,$0
$L8:
	sw	$2,16($fp)
	lw	$2,0($fp)
	bne	$2,$0,$L9
	nop

	lw	$2,4($fp)
	beq	$2,$0,$L10
	nop

$L9:
	li	$2,1			# 0x1
	b	$L11
	nop

$L10:
	move	$2,$0
$L11:
	sw	$2,20($fp)
	lw	$3,0($fp)
	lw	$2,4($fp)
	xor	$2,$3,$2
	sltu	$2,$2,1
	andi	$2,$2,0x00ff
	sw	$2,16($fp)
	lw	$3,0($fp)
	lw	$2,4($fp)
	xor	$2,$3,$2
	sltu	$2,$2,1
	andi	$2,$2,0x00ff
	sw	$2,20($fp)
	lw	$3,0($fp)
	lw	$2,4($fp)
	slt	$2,$2,$3
	andi	$2,$2,0x00ff
	sw	$2,16($fp)
	lw	$3,0($fp)
	lw	$2,4($fp)
	slt	$2,$2,$3
	andi	$2,$2,0x00ff
	sw	$2,20($fp)
	lw	$3,0($fp)
	lw	$2,4($fp)
	slt	$2,$3,$2
	andi	$2,$2,0x00ff
	sw	$2,16($fp)
	lw	$3,0($fp)
	lw	$2,4($fp)
	slt	$2,$3,$2
	andi	$2,$2,0x00ff
	sw	$2,20($fp)
	lw	$3,0($fp)
	lw	$2,4($fp)
	slt	$2,$3,$2
	xori	$2,$2,0x1
	andi	$2,$2,0x00ff
	sw	$2,16($fp)
	lw	$3,0($fp)
	lw	$2,4($fp)
	slt	$2,$3,$2
	xori	$2,$2,0x1
	andi	$2,$2,0x00ff
	sw	$2,20($fp)
	lw	$3,0($fp)
	lw	$2,4($fp)
	slt	$2,$2,$3
	xori	$2,$2,0x1
	andi	$2,$2,0x00ff
	sw	$2,16($fp)
	lw	$3,0($fp)
	lw	$2,4($fp)
	slt	$2,$2,$3
	xori	$2,$2,0x1
	andi	$2,$2,0x00ff
	sw	$2,20($fp)
	lw	$2,0($fp)
	sltu	$2,$2,1
	andi	$2,$2,0x00ff
	sw	$2,16($fp)
	lw	$2,0($fp)
	sltu	$2,$2,1
	andi	$2,$2,0x00ff
	sw	$2,20($fp)
	lw	$3,8($fp)
	lw	$2,12($fp)
	srl	$2,$3,$2
	sw	$2,16($fp)
	lw	$3,8($fp)
	lw	$2,12($fp)
	srl	$2,$3,$2
	sw	$2,20($fp)
	lw	$3,8($fp)
	lw	$2,12($fp)
	teq	$2,$0,7
	divu	$0,$3,$2
	mfhi	$2
	mflo	$2
	sw	$2,16($fp)
	lw	$3,8($fp)
	lw	$2,12($fp)
	teq	$2,$0,7
	divu	$0,$3,$2
	mfhi	$2
	mflo	$2
	sw	$2,20($fp)
	lw	$3,8($fp)
	lw	$2,12($fp)
	teq	$2,$0,7
	divu	$0,$3,$2
	mfhi	$2
	sw	$2,16($fp)
	lw	$3,8($fp)
	lw	$2,12($fp)
	teq	$2,$0,7
	divu	$0,$3,$2
	mfhi	$2
	sw	$2,20($fp)
	lw	$2,8($fp)
	beq	$2,$0,$L12
	nop

	lw	$2,12($fp)
	beq	$2,$0,$L12
	nop

	li	$2,1			# 0x1
	b	$L13
	nop

$L12:
	move	$2,$0
$L13:
	sw	$2,16($fp)
	lw	$2,8($fp)
	beq	$2,$0,$L14
	nop

	lw	$2,12($fp)
	beq	$2,$0,$L14
	nop

	li	$2,1			# 0x1
	b	$L15
	nop

$L14:
	move	$2,$0
$L15:
	sw	$2,20($fp)
	lw	$2,8($fp)
	bne	$2,$0,$L16
	nop

	lw	$2,12($fp)
	beq	$2,$0,$L17
	nop

$L16:
	li	$2,1			# 0x1
	b	$L18
	nop

$L17:
	move	$2,$0
$L18:
	sw	$2,16($fp)
	lw	$2,8($fp)
	bne	$2,$0,$L19
	nop

	lw	$2,12($fp)
	beq	$2,$0,$L20
	nop

$L19:
	li	$2,1			# 0x1
	b	$L21
	nop

$L20:
	move	$2,$0
$L21:
	sw	$2,20($fp)
	lw	$3,8($fp)
	lw	$2,12($fp)
	xor	$2,$3,$2
	sltu	$2,$2,1
	andi	$2,$2,0x00ff
	sw	$2,16($fp)
	lw	$3,8($fp)
	lw	$2,12($fp)
	xor	$2,$3,$2
	sltu	$2,$2,1
	andi	$2,$2,0x00ff
	sw	$2,20($fp)
	lw	$3,8($fp)
	lw	$2,12($fp)
	sltu	$2,$2,$3
	andi	$2,$2,0x00ff
	sw	$2,16($fp)
	lw	$3,8($fp)
	lw	$2,12($fp)
	sltu	$2,$2,$3
	andi	$2,$2,0x00ff
	sw	$2,20($fp)
	lw	$3,8($fp)
	lw	$2,12($fp)
	sltu	$2,$3,$2
	andi	$2,$2,0x00ff
	sw	$2,16($fp)
	lw	$3,8($fp)
	lw	$2,12($fp)
	sltu	$2,$3,$2
	andi	$2,$2,0x00ff
	sw	$2,20($fp)
	lw	$3,8($fp)
	lw	$2,12($fp)
	sltu	$2,$3,$2
	xori	$2,$2,0x1
	andi	$2,$2,0x00ff
	sw	$2,16($fp)
	lw	$3,8($fp)
	lw	$2,12($fp)
	sltu	$2,$3,$2
	xori	$2,$2,0x1
	andi	$2,$2,0x00ff
	sw	$2,20($fp)
	lw	$3,8($fp)
	lw	$2,12($fp)
	sltu	$2,$2,$3
	xori	$2,$2,0x1
	andi	$2,$2,0x00ff
	sw	$2,16($fp)
	lw	$3,8($fp)
	lw	$2,12($fp)
	sltu	$2,$2,$3
	xori	$2,$2,0x1
	andi	$2,$2,0x00ff
	sw	$2,20($fp)
	lw	$2,8($fp)
	sltu	$2,$2,1
	andi	$2,$2,0x00ff
	sw	$2,16($fp)
	lw	$2,8($fp)
	sltu	$2,$2,1
	andi	$2,$2,0x00ff
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

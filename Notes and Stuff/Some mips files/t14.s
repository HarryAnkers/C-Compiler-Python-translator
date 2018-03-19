
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
	lw	$3,8($fp)
	lw	$2,12($fp)
	slt	$2,$2,$3
	beq	$2,$0,$L2
	nop

	li	$2,123404288			# 0x75b0000
	ori	$2,$2,0xcd15
	b	$L3
	nop

$L2:
	move	$2,$0
$L3:
	move	$sp,$fp
	lw	$fp,4($sp)
	addiu	$sp,$sp,8
	j	$31
	nop

	.file	1 "t33.c"
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
	.word	3
	.globl	x
	.align	2
	.type	x, @object
	.size	x, 4
x:
	.word	-332
	.globl	a
	.align	2
	.type	a, @object
	.size	a, 4
a:
	.word	7
	.globl	b
	.align	2
	.type	b, @object
	.size	b, 4
b:
	.word	6
	.globl	c
	.type	c, @object
	.size	c, 1
c:
	.byte	5
	.globl	d
	.align	1
	.type	d, @object
	.size	d, 2
d:
	.half	4
	.globl	e
	.align	2
	.type	e, @object
	.size	e, 4
e:
	.word	3
	.globl	f
	.align	2
	.type	f, @object
	.size	f, 4
f:
	.word	1073741824
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
	lw	$3,%lo(i)($2)
	lui	$2,%hi(x)
	lw	$2,%lo(x)($2)
	addu	$3,$3,$2
	lui	$2,%hi(a)
	lw	$2,%lo(a)($2)
	addu	$2,$3,$2
	move	$3,$2
	lui	$2,%hi(b)
	lw	$2,%lo(b)($2)
	addu	$2,$3,$2
	lui	$3,%hi(c)
	lb	$3,%lo(c)($3)
	addu	$2,$2,$3
	lui	$3,%hi(d)
	lh	$3,%lo(d)($3)
	addu	$2,$2,$3
	lui	$3,%hi(e)
	lw	$3,%lo(e)($3)
	addu	$2,$2,$3
	mtc1	$2,$f0
	cvt.d.w	$f0,$f0
	bgez	$2,$L2
	nop

	lui	$2,%hi($LC0)
	ldc1	$f2,%lo($LC0)($2)
	add.d	$f0,$f0,$f2
$L2:
	cvt.s.d	$f2,$f0
	lui	$2,%hi(f)
	lwc1	$f0,%lo(f)($2)
	add.s	$f0,$f2,$f0
	trunc.w.s $f0,$f0
	mfc1	$3,$f0
	lui	$2,%hi(i)
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
	.rdata
	.align	3
$LC0:
	.word	1106247680
	.word	0
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.9) 5.4.0 20160609"

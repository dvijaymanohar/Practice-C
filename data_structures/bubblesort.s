	.file	"bubblesort.c"
	.section	.rodata
.LC0:
	.string	"Enter the number of elements"
.LC1:
	.string	"%d"
.LC2:
	.string	"Enter the elements"
.LC3:
	.string	"\nThe complexity is %d\n"
	.text
.globl main
	.type	main, @function
main:
	leal	4(%esp), %ecx
	andl	$-16, %esp
	pushl	-4(%ecx)
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ecx
	subl	$52, %esp
	movl	$0, -8(%ebp)
	movl	$.LC0, (%esp)
	call	puts
	leal	-32(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC1, (%esp)
	call	scanf
	movl	-32(%ebp), %eax
	sall	$2, %eax
	movl	%eax, (%esp)
	call	malloc
	movl	%eax, -28(%ebp)
	movl	$.LC2, (%esp)
	call	puts
	movl	$0, -24(%ebp)
	jmp	.L2
.L3:
	movl	-24(%ebp), %eax
	sall	$2, %eax
	addl	-28(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC1, (%esp)
	call	scanf
	addl	$1, -24(%ebp)
.L2:
	movl	-32(%ebp), %eax
	cmpl	%eax, -24(%ebp)
	jl	.L3
	movl	$0, -24(%ebp)
	jmp	.L5
.L6:
	movl	-24(%ebp), %eax
	sall	$2, %eax
	addl	-28(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$.LC1, (%esp)
	call	printf
	addl	$1, -24(%ebp)
.L5:
	movl	-32(%ebp), %eax
	cmpl	%eax, -24(%ebp)
	jl	.L6
	movl	$10, (%esp)
	call	putchar
	movl	$0, -20(%ebp)
	jmp	.L8
.L9:
	movl	$0, -24(%ebp)
	jmp	.L10
.L11:
	movl	-24(%ebp), %eax
	sall	$2, %eax
	addl	-28(%ebp), %eax
	movl	(%eax), %edx
	movl	-24(%ebp), %eax
	sall	$2, %eax
	addl	-28(%ebp), %eax
	addl	$4, %eax
	movl	(%eax), %eax
	cmpl	%eax, %edx
	jle	.L12
	movl	-24(%ebp), %eax
	sall	$2, %eax
	addl	-28(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -12(%ebp)
	movl	-24(%ebp), %eax
	sall	$2, %eax
	movl	%eax, %edx
	addl	-28(%ebp), %edx
	movl	-24(%ebp), %eax
	sall	$2, %eax
	addl	-28(%ebp), %eax
	addl	$4, %eax
	movl	(%eax), %eax
	movl	%eax, (%edx)
	movl	-24(%ebp), %eax
	sall	$2, %eax
	addl	-28(%ebp), %eax
	leal	4(%eax), %edx
	movl	-12(%ebp), %eax
	movl	%eax, (%edx)
	addl	$1, -8(%ebp)
.L12:
	addl	$1, -24(%ebp)
.L10:
	movl	-32(%ebp), %eax
	subl	$1, %eax
	cmpl	-24(%ebp), %eax
	jg	.L11
	movl	$0, -16(%ebp)
	jmp	.L15
.L16:
	movl	-16(%ebp), %eax
	sall	$2, %eax
	addl	-28(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$.LC1, (%esp)
	call	printf
	addl	$1, -16(%ebp)
.L15:
	movl	-32(%ebp), %eax
	cmpl	%eax, -16(%ebp)
	jl	.L16
	movl	$10, (%esp)
	call	putchar
	addl	$1, -20(%ebp)
.L8:
	movl	-32(%ebp), %eax
	subl	$1, %eax
	cmpl	-20(%ebp), %eax
	jg	.L9
	movl	$0, -16(%ebp)
	jmp	.L19
.L20:
	movl	-16(%ebp), %eax
	sall	$2, %eax
	addl	-28(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$.LC1, (%esp)
	call	printf
	addl	$1, -16(%ebp)
.L19:
	movl	-32(%ebp), %eax
	cmpl	%eax, -16(%ebp)
	jl	.L20
	movl	-8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC3, (%esp)
	call	printf
	movl	$0, %eax
	addl	$52, %esp
	popl	%ecx
	popl	%ebp
	leal	-4(%ecx), %esp
	ret
	.size	main, .-main
	.ident	"GCC: (GNU) 4.1.0 20060304 (Red Hat 4.1.0-3)"
	.section	.note.GNU-stack,"",@progbits

	.file	"listmain.c"
	.section	.rodata
.LC0:
	.string	"List is not Cteate"
.LC1:
	.string	"List is Create"
.LC2:
	.string	"Enter ur Choice"
	.align 4
.LC3:
	.string	" 1 -- Insert_Frist\n 2 -- Insert_Last\n 3 -- Insert Before\n 4 -- Insert After\n 5 -- Delete_Frist\n 6 -- Delete_Last\n 7 -- Delete Before\n 8 -- Delete After\n 9 -- Print"
.LC4:
	.string	"%d"
.LC5:
	.string	"Enter the value"
	.align 4
.LC6:
	.string	"Enter the value of Data and Position"
.LC7:
	.string	"%d %d"
	.align 4
.LC8:
	.string	"Delete Operation is Successfull and value is %d"
.LC9:
	.string	"enter the position "
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
	subl	$84, %esp
	call	linklist_create
	movl	%eax, -40(%ebp)
	cmpl	$0, -40(%ebp)
	jne	.L2
	movl	$.LC0, (%esp)
	call	puts
	movl	$0, %eax
	movl	%eax, -76(%ebp)
	jmp	.L1
.L2:
	movl	$.LC1, (%esp)
	call	puts
	jmp	.L17
.L4:
.L17:
	movl	$.LC2, (%esp)
	call	puts
	movl	$.LC3, (%esp)
	call	puts
	leal	-44(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC4, (%esp)
	call	scanf
	movl	-44(%ebp), %eax
	movl	%eax, -72(%ebp)
	cmpl	$9, -72(%ebp)
	ja	.L4
	movl	-72(%ebp), %edx
	movl	.L15(,%edx,4), %eax
	jmp	*%eax
	.section	.rodata
	.align 4
	.align 4
.L15:
	.long	.L4
	.long	.L6
	.long	.L7
	.long	.L8
	.long	.L9
	.long	.L10
	.long	.L11
	.long	.L12
	.long	.L13
	.long	.L14
	.text
.L6:
	movl	$.LC5, (%esp)
	call	puts
	movl	$4, (%esp)
	call	malloc
	movl	%eax, -36(%ebp)
	movl	-36(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC4, (%esp)
	call	scanf
	movl	-36(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-40(%ebp), %eax
	movl	%eax, (%esp)
	call	linklist_insert_frist
	jmp	.L4
.L7:
	movl	$.LC5, (%esp)
	call	puts
	movl	$4, (%esp)
	call	malloc
	movl	%eax, -32(%ebp)
	movl	-32(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC4, (%esp)
	call	scanf
	movl	-32(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-40(%ebp), %eax
	movl	%eax, (%esp)
	call	linklist_insert_last
	jmp	.L4
.L8:
	movl	$.LC6, (%esp)
	call	puts
	movl	$4, (%esp)
	call	malloc
	movl	%eax, -28(%ebp)
	leal	-48(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	-28(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC7, (%esp)
	call	scanf
	movl	-48(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	-28(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-40(%ebp), %eax
	movl	%eax, (%esp)
	call	linklist_insert_before
	jmp	.L4
.L9:
	movl	$.LC6, (%esp)
	call	puts
	movl	$4, (%esp)
	call	malloc
	movl	%eax, -24(%ebp)
	leal	-52(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	-24(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC7, (%esp)
	call	scanf
	movl	-52(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	-24(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-40(%ebp), %eax
	movl	%eax, (%esp)
	call	linklist_insert_before
	jmp	.L4
.L10:
	movl	-40(%ebp), %eax
	movl	%eax, (%esp)
	call	linklist_delete_frist
	movl	%eax, -20(%ebp)
	movl	-20(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$.LC8, (%esp)
	call	printf
	movl	-20(%ebp), %eax
	movl	%eax, (%esp)
	call	free
	jmp	.L4
.L11:
	movl	-40(%ebp), %eax
	movl	%eax, (%esp)
	call	linklist_delete_last
	movl	%eax, -16(%ebp)
	movl	-16(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$.LC8, (%esp)
	call	printf
	movl	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	free
	jmp	.L4
.L12:
	movl	$.LC9, (%esp)
	call	puts
	leal	-56(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC4, (%esp)
	call	scanf
	movl	-56(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-40(%ebp), %eax
	movl	%eax, (%esp)
	call	linklist_delete_before
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$.LC8, (%esp)
	call	printf
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	free
	jmp	.L4
.L13:
	movl	$.LC9, (%esp)
	call	puts
	leal	-60(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC4, (%esp)
	call	scanf
	movl	-60(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-40(%ebp), %eax
	movl	%eax, (%esp)
	call	linklist_delete_after
	movl	%eax, -8(%ebp)
	movl	-8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$.LC8, (%esp)
	call	printf
	movl	-8(%ebp), %eax
	movl	%eax, (%esp)
	call	free
	jmp	.L4
.L14:
	movl	$10, (%esp)
	call	putchar
	movl	-40(%ebp), %eax
	movl	%eax, (%esp)
	call	linklist_print
	jmp	.L4
.L1:
	movl	-76(%ebp), %eax
	addl	$84, %esp
	popl	%ecx
	popl	%ebp
	leal	-4(%ecx), %esp
	ret
	.size	main, .-main
	.ident	"GCC: (GNU) 4.1.0 20060304 (Red Hat 4.1.0-3)"
	.section	.note.GNU-stack,"",@progbits

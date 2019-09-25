	.file	"app.c"
	.section	.rodata
.LC0:
	.string	"lib test"
.LC1:
	.string	"end"
	.text
.globl main
	.type	main, @function
main:
	pushl	%ebp
	movl	%esp, %ebp
	andl	$-16, %esp
	subl	$32, %esp
	movl	$30, 24(%esp)
	movl	$40, 28(%esp)
	movl	$.LC0, (%esp)
	call	puts
	call	test1
	movl	$.LC1, (%esp)
	call	puts
	movl	$0, %eax
	leave
	ret
	.size	main, .-main
	.ident	"GCC: (GNU) 4.4.4 20100630 (Red Hat 4.4.4-10)"
	.section	.note.GNU-stack,"",@progbits

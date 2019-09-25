	.file	"one.c"
	.section	.rodata
.LC0:
	.string	"\n\t\t*==================*"
.LC1:
	.string	"\n\t\t   Veda Solutions"
.LC2:
	.string	"\n\t\t*==================*\n"
	.text
.globl main
	.type	main, @function
main:
	pushl	%ebp
	movl	%esp, %ebp
	andl	$-16, %esp
	subl	$16, %esp
	movl	$.LC0, %eax
	movl	%eax, (%esp)
	call	printf
	movl	$.LC1, %eax
	movl	%eax, (%esp)
	call	printf
	movl	$.LC2, (%esp)
	call	puts
	movl	$0, %eax
	leave
	ret
	.size	main, .-main
	.ident	"GCC: (GNU) 4.4.4 20100630 (Red Hat 4.4.4-10)"
	.section	.note.GNU-stack,"",@progbits

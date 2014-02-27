	.file	"test.c"
	.section	.rodata
.LC0:
	.string	"print the array %s"
.LC1:
	.string	"first element s[0]: %c"
.LC2:
	.string	"print this number %c"
	.text
.globl main
	.type	main, @function
main:
	pushl	%ebp
	movl	%esp, %ebp
	andl	$-16, %esp
	addl	$-128, %esp
	movl	%gs:20, %eax
	movl	%eax, 124(%esp)
	xorl	%eax, %eax
	movl	$65, 20(%esp)
	movl	20(%esp), %eax
	movb	%al, 24(%esp)
	movb	$0, 25(%esp)
	movl	$.LC0, %eax
	leal	24(%esp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	printf
	movl	$48, 20(%esp)
	movzbl	24(%esp), %eax
	movsbl	%al, %edx
	movl	$.LC1, %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	printf
	movl	$.LC2, %eax
	movl	20(%esp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	printf
	leal	24(%esp), %eax
	movl	%eax, (%esp)
	call	haha
	movl	124(%esp), %edx
	xorl	%gs:20, %edx
	je	.L2
	call	__stack_chk_fail
.L2:
	leave
	ret
	.size	main, .-main
.globl haha
	.type	haha, @function
haha:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$40, %esp
	movl	$0, -12(%ebp)
	movl	-12(%ebp), %eax
	addl	8(%ebp), %eax
	movb	$65, (%eax)
	addl	$1, -12(%ebp)
	movl	-12(%ebp), %eax
	addl	8(%ebp), %eax
	movb	$0, (%eax)
	movl	8(%ebp), %eax
	movzbl	(%eax), %eax
	movsbl	%al, %edx
	movl	$.LC1, %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	printf
	leave
	ret
	.size	haha, .-haha
	.ident	"GCC: (Ubuntu/Linaro 4.5.2-8ubuntu4) 4.5.2"
	.section	.note.GNU-stack,"",@progbits

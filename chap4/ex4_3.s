	.file	"ex4_3.c"
	.comm	mystack,800,32
	.comm	stack_index,4,4
	.comm	buff,400,32
	.comm	buffindex,4,4
	.section	.rodata
.LC0:
	.string	"POLISH CALCULATION "
.LC1:
	.string	"\t\t...pushed %s to stack\n"
.LC2:
	.string	"\t\tADD OPERATION"
.LC3:
	.string	"Print the stack:"
.LC4:
	.string	"mystack[%i]: %f  "
.LC6:
	.string	"\t\tSUBTRACT OPERATION"
.LC7:
	.string	"\t\tMULTIPLY OPERATION"
.LC8:
	.string	"\t\tDIVIDE OPERATION"
.LC9:
	.string	"error: division by zero !"
.LC10:
	.string	"\t\tMODULO OPERATION"
.LC11:
	.string	"\t\tResult is : %f\n"
.LC12:
	.string	"Unknown command ! "
	.text
.globl main
	.type	main, @function
main:
	pushl	%ebp
	movl	%esp, %ebp
	andl	$-16, %esp
	subl	$160, %esp
	movl	%gs:20, %eax
	movl	%eax, 156(%esp)
	xorl	%eax, %eax
	movl	$0, stack_index
	movl	$0, buffindex
	movl	$0, 52(%esp)
	movl	$.LC0, (%esp)
	call	puts
	jmp	.L2
.L21:
	movl	48(%esp), %eax
	subl	$10, %eax
	cmpl	$38, %eax
	ja	.L3
	movl	.L12(,%eax,4), %eax
	jmp	*%eax
	.section	.rodata
	.align 4
	.align 4
.L12:
	.long	.L4
	.long	.L3
	.long	.L3
	.long	.L3
	.long	.L3
	.long	.L3
	.long	.L3
	.long	.L3
	.long	.L3
	.long	.L3
	.long	.L3
	.long	.L3
	.long	.L3
	.long	.L3
	.long	.L3
	.long	.L3
	.long	.L3
	.long	.L3
	.long	.L3
	.long	.L3
	.long	.L3
	.long	.L3
	.long	.L25
	.long	.L3
	.long	.L3
	.long	.L3
	.long	.L3
	.long	.L6
	.long	.L3
	.long	.L3
	.long	.L3
	.long	.L3
	.long	.L7
	.long	.L8
	.long	.L3
	.long	.L9
	.long	.L3
	.long	.L10
	.long	.L11
	.text
.L11:
	movl	$.LC1, %eax
	leal	56(%esp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	printf
	leal	56(%esp), %eax
	movl	%eax, (%esp)
	call	atof
	fstpl	(%esp)
	call	push
	jmp	.L2
.L8:
	movl	$.LC2, (%esp)
	call	puts
	call	printtop
	call	pop
	fstpl	24(%esp)
	call	pop
	faddl	24(%esp)
	fstpl	40(%esp)
	movl	$.LC3, %eax
	movl	%eax, (%esp)
	call	printf
	jmp	.L13
.L26:
	fstp	%st(0)
.L14:
	movl	52(%esp), %eax
	fldl	mystack(,%eax,8)
	addl	$1, 52(%esp)
	movl	$.LC4, %eax
	fstpl	8(%esp)
	movl	52(%esp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	printf
.L13:
	movl	52(%esp), %eax
	fldl	mystack(,%eax,8)
	fldz
	fucomip	%st(1), %st
	jp	.L26
	fldz
	fucomip	%st(1), %st
	fstp	%st(0)
	jne	.L14
	fldl	40(%esp)
	fstpl	(%esp)
	call	push
	jmp	.L2
.L9:
	movl	$.LC6, (%esp)
	call	puts
	call	pop
	fstpl	32(%esp)
	call	pop
	fldl	32(%esp)
	fsubp	%st, %st(1)
	fstpl	40(%esp)
	fldl	40(%esp)
	fstpl	(%esp)
	call	push
	jmp	.L2
.L7:
	movl	$.LC7, (%esp)
	call	puts
	call	pop
	fstpl	16(%esp)
	call	pop
	fmull	16(%esp)
	fstpl	(%esp)
	call	push
	jmp	.L2
.L10:
	movl	$.LC8, (%esp)
	call	puts
	call	pop
	fstpl	32(%esp)
	fldl	32(%esp)
	fldz
	fucomip	%st(1), %st
	fstp	%st(0)
	jp	.L23
	fldl	32(%esp)
	fldz
	fucomip	%st(1), %st
	fstp	%st(0)
	je	.L24
.L23:
	call	pop
	fldl	32(%esp)
	fdivp	%st, %st(1)
	fstpl	40(%esp)
	jmp	.L17
.L24:
	movl	$.LC9, (%esp)
	call	puts
.L17:
	fldl	40(%esp)
	fstpl	(%esp)
	call	push
	jmp	.L2
.L6:
	movl	$.LC10, (%esp)
	call	puts
	call	pop
	fstpl	32(%esp)
	call	pop
	fldl	32(%esp)
	fld	%st(1)
	fld	%st(1)
.L18:
	fprem
	fnstsw	%ax
	sahf
	jp	.L18
	fstp	%st(1)
	fucomi	%st(0), %st
	jp	.L27
	fucomi	%st(0), %st
	je	.L28
	fstp	%st(0)
	fxch	%st(1)
	jmp	.L20
.L27:
	fstp	%st(0)
	fxch	%st(1)
.L20:
	fstpl	8(%esp)
	fstpl	(%esp)
	call	fmod
	jmp	.L19
.L28:
	fstp	%st(1)
	fstp	%st(1)
.L19:
	fstpl	40(%esp)
	fldl	40(%esp)
	fstpl	(%esp)
	call	push
	jmp	.L2
.L4:
	call	pop
	movl	$.LC11, %eax
	fstpl	4(%esp)
	movl	%eax, (%esp)
	call	printf
	jmp	.L2
.L3:
	movl	$.LC12, (%esp)
	call	puts
	jmp	.L2
.L25:
	nop
.L2:
	leal	56(%esp), %eax
	movl	%eax, (%esp)
	call	getopt
	movl	%eax, 48(%esp)
	cmpl	$-1, 48(%esp)
	jne	.L21
	movl	156(%esp), %edx
	xorl	%gs:20, %edx
	je	.L22
	call	__stack_chk_fail
.L22:
	leave
	ret
	.size	main, .-main
.globl getopt
	.type	getopt, @function
getopt:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%esi
	pushl	%ebx
	subl	$32, %esp
	movl	$0, -20(%ebp)
	movl	$0, -16(%ebp)
.L31:
	call	getch
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, %edx
	movl	8(%ebp), %eax
	movb	%dl, (%eax)
	movl	8(%ebp), %eax
	movzbl	(%eax), %eax
	cmpb	$32, %al
	jne	.L30
	cmpl	$9, -12(%ebp)
	je	.L31
.L30:
	cmpl	$45, -12(%ebp)
	jne	.L32
	call	__ctype_b_loc
	movl	(%eax), %ebx
	call	getch
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	addl	%eax, %eax
	leal	(%ebx,%eax), %eax
	movzwl	(%eax), %eax
	movzwl	%ax, %eax
	andl	$2048, %eax
	testl	%eax, %eax
	je	.L33
	addl	$1, -16(%ebp)
	movl	-16(%ebp), %eax
	addl	8(%ebp), %eax
	movl	-12(%ebp), %edx
	movb	%dl, (%eax)
	nop
.L34:
	call	__ctype_b_loc
	movl	(%eax), %esi
	addl	$1, -16(%ebp)
	movl	-16(%ebp), %eax
	movl	%eax, %ebx
	addl	8(%ebp), %ebx
	call	getch
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	movb	%al, (%ebx)
	movzbl	(%ebx), %eax
	movsbl	%al, %eax
	addl	%eax, %eax
	leal	(%esi,%eax), %eax
	movzwl	(%eax), %eax
	movzwl	%ax, %eax
	andl	$2048, %eax
	testl	%eax, %eax
	jne	.L34
	addl	$1, -16(%ebp)
	movl	-16(%ebp), %eax
	addl	8(%ebp), %eax
	movb	$0, (%eax)
	movl	$48, %eax
	jmp	.L35
.L33:
	movl	$45, %eax
	jmp	.L35
.L32:
	call	__ctype_b_loc
	movl	(%eax), %eax
	movl	-12(%ebp), %edx
	addl	%edx, %edx
	addl	%edx, %eax
	movzwl	(%eax), %eax
	movzwl	%ax, %eax
	andl	$2048, %eax
	testl	%eax, %eax
	jne	.L36
	cmpl	$46, -12(%ebp)
	je	.L36
	cmpl	$45, -12(%ebp)
	je	.L36
	movl	-12(%ebp), %eax
	jmp	.L35
.L36:
	call	__ctype_b_loc
	movl	(%eax), %eax
	movl	-12(%ebp), %edx
	addl	%edx, %edx
	addl	%edx, %eax
	movzwl	(%eax), %eax
	movzwl	%ax, %eax
	andl	$2048, %eax
	testl	%eax, %eax
	je	.L37
	nop
.L38:
	call	__ctype_b_loc
	movl	(%eax), %esi
	addl	$1, -16(%ebp)
	movl	-16(%ebp), %eax
	movl	%eax, %ebx
	addl	8(%ebp), %ebx
	call	getch
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	movb	%al, (%ebx)
	movzbl	(%ebx), %eax
	movsbl	%al, %eax
	addl	%eax, %eax
	leal	(%esi,%eax), %eax
	movzwl	(%eax), %eax
	movzwl	%ax, %eax
	andl	$2048, %eax
	testl	%eax, %eax
	jne	.L38
.L37:
	cmpl	$46, -12(%ebp)
	jne	.L39
	nop
.L40:
	call	__ctype_b_loc
	movl	(%eax), %esi
	addl	$1, -16(%ebp)
	movl	-16(%ebp), %eax
	movl	%eax, %ebx
	addl	8(%ebp), %ebx
	call	getch
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	movb	%al, (%ebx)
	movzbl	(%ebx), %eax
	movsbl	%al, %eax
	addl	%eax, %eax
	leal	(%esi,%eax), %eax
	movzwl	(%eax), %eax
	movzwl	%ax, %eax
	andl	$2048, %eax
	testl	%eax, %eax
	jne	.L40
.L39:
	movl	-16(%ebp), %eax
	addl	8(%ebp), %eax
	movb	$0, (%eax)
	cmpl	$-1, -12(%ebp)
	je	.L41
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	ungetch
.L41:
	movl	$48, %eax
.L35:
	addl	$32, %esp
	popl	%ebx
	popl	%esi
	popl	%ebp
	ret
	.size	getopt, .-getopt
	.section	.rodata
.LC14:
	.string	"error: My stack is empty"
	.text
.globl pop
	.type	pop, @function
pop:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	movl	stack_index, %eax
	testl	%eax, %eax
	jle	.L43
	movl	stack_index, %eax
	subl	$1, %eax
	movl	%eax, stack_index
	movl	stack_index, %eax
	fldl	mystack(,%eax,8)
	jmp	.L44
.L43:
	movl	$.LC14, (%esp)
	call	puts
	fldz
.L44:
	leave
	ret
	.size	pop, .-pop
	.section	.rodata
.LC15:
	.string	"error: My Stack is overflow"
	.text
.globl push
	.type	push, @function
push:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$40, %esp
	movl	8(%ebp), %eax
	movl	%eax, -16(%ebp)
	movl	12(%ebp), %eax
	movl	%eax, -12(%ebp)
	movl	stack_index, %eax
	cmpl	$100, %eax
	jle	.L46
	movl	$.LC15, (%esp)
	call	puts
	jmp	.L45
.L46:
	movl	stack_index, %eax
	fldl	-16(%ebp)
	fstpl	mystack(,%eax,8)
	addl	$1, %eax
	movl	%eax, stack_index
.L45:
	leave
	ret
	.size	push, .-push
	.section	.rodata
.LC16:
	.string	"[buffer(%d)]: %c\n"
.LC17:
	.string	"[input]: %c\n"
	.text
.globl getch
	.type	getch, @function
getch:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$40, %esp
	movl	buffindex, %eax
	testl	%eax, %eax
	jle	.L49
	movl	buffindex, %eax
	subl	$1, %eax
	movl	%eax, buffindex
	movl	buffindex, %eax
	movl	buff(,%eax,4), %eax
	movl	%eax, -12(%ebp)
	movl	buffindex, %edx
	movl	$.LC16, %eax
	movl	-12(%ebp), %ecx
	movl	%ecx, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	printf
	jmp	.L50
.L49:
	call	getchar
	movl	%eax, -12(%ebp)
	movl	$.LC17, %eax
	movl	-12(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	printf
.L50:
	movl	-12(%ebp), %eax
	leave
	ret
	.size	getch, .-getch
	.section	.rodata
.LC18:
	.string	"\tbuffer saving: %c\n"
.LC19:
	.string	"error: BUFFER IS LIMITED"
	.text
.globl ungetch
	.type	ungetch, @function
ungetch:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	movl	$.LC18, %eax
	movl	8(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	printf
	movl	buffindex, %eax
	cmpl	$100, %eax
	jle	.L52
	movl	$.LC19, %eax
	movl	%eax, (%esp)
	call	printf
	jmp	.L51
.L52:
	movl	buffindex, %eax
	movl	8(%ebp), %edx
	movl	%edx, buff(,%eax,4)
	addl	$1, %eax
	movl	%eax, buffindex
.L51:
	leave
	ret
	.size	ungetch, .-ungetch
	.section	.rodata
.LC20:
	.string	"Top element in stack is: %f\n"
	.text
.globl printtop
	.type	printtop, @function
printtop:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	movl	stack_index, %eax
	subl	$1, %eax
	fldl	mystack(,%eax,8)
	movl	$.LC20, %eax
	fstpl	4(%esp)
	movl	%eax, (%esp)
	call	printf
	leave
	ret
	.size	printtop, .-printtop
.globl clearstack
	.type	clearstack, @function
clearstack:
	pushl	%ebp
	movl	%esp, %ebp
	movl	$0, stack_index
	popl	%ebp
	ret
	.size	clearstack, .-clearstack
.globl duplicatetop
	.type	duplicatetop, @function
duplicatetop:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$40, %esp
	call	pop
	fstpl	-16(%ebp)
	fldl	-16(%ebp)
	fstpl	(%esp)
	call	push
	fldl	-16(%ebp)
	fstpl	(%esp)
	call	push
	leave
	ret
	.size	duplicatetop, .-duplicatetop
.globl swaptop
	.type	swaptop, @function
swaptop:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$40, %esp
	call	pop
	fstpl	-16(%ebp)
	call	pop
	fstpl	-24(%ebp)
	fldl	-16(%ebp)
	fstpl	(%esp)
	call	push
	fldl	-24(%ebp)
	fstpl	(%esp)
	call	push
	leave
	ret
	.size	swaptop, .-swaptop
	.ident	"GCC: (Ubuntu/Linaro 4.5.2-8ubuntu4) 4.5.2"
	.section	.note.GNU-stack,"",@progbits

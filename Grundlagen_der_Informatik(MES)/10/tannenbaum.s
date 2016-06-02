	.file	"tannenbaum.c"
	.section	.rodata
.LC0:
	.string	"III"
	.text
	.globl	main
	.type	main, @function
main:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movl	%edi, -36(%rbp)
	movq	%rsi, -48(%rbp)
	leaq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	time
	movl	%eax, %edi
	call	srand
	movq	-48(%rbp), %rax
	addq	$8, %rax
	movq	(%rax), %rax
	movq	%rax, %rdi
	call	atoi
	movl	%eax, -16(%rbp)
	movl	$0, -12(%rbp)
	movl	-16(%rbp), %eax
	subl	$1, %eax
	movl	%eax, -32(%rbp)
	jmp	.L2
.L11:
	movl	$0, -28(%rbp)
	jmp	.L3
.L4:
	movl	$32, %edi
	call	putchar
	addl	$1, -28(%rbp)
.L3:
	movl	-28(%rbp), %eax
	cmpl	-32(%rbp), %eax
	jl	.L4
	movl	$0, -24(%rbp)
	jmp	.L5
.L8:
	call	rand
	movl	%eax, %ecx
	movl	$780903145, %edx
	movl	%ecx, %eax
	imull	%edx
	sarl	%edx
	movl	%ecx, %eax
	sarl	$31, %eax
	subl	%eax, %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	subl	%eax, %ecx
	movl	%ecx, %edx
	testl	%edx, %edx
	je	.L6
	movl	$42, %edi
	call	putchar
	jmp	.L7
.L6:
	movl	$79, %edi
	call	putchar
.L7:
	addl	$1, -24(%rbp)
.L5:
	movl	-32(%rbp), %eax
	movl	-16(%rbp), %edx
	subl	%eax, %edx
	movl	%edx, %eax
	addl	%eax, %eax
	subl	$1, %eax
	cmpl	-24(%rbp), %eax
	jg	.L8
	movl	$0, -28(%rbp)
	jmp	.L9
.L10:
	movl	$32, %edi
	call	putchar
	addl	$1, -28(%rbp)
.L9:
	movl	-28(%rbp), %eax
	cmpl	-32(%rbp), %eax
	jl	.L10
	movl	$10, %edi
	call	putchar
	subl	$1, -32(%rbp)
.L2:
	cmpl	$0, -32(%rbp)
	jns	.L11
	movl	$0, -20(%rbp)
	jmp	.L12
.L13:
	movl	$32, %edi
	call	putchar
	addl	$1, -20(%rbp)
.L12:
	movl	-16(%rbp), %eax
	subl	$2, %eax
	cmpl	-20(%rbp), %eax
	jg	.L13
	movl	$.LC0, %edi
	call	puts
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 4.8.4-2ubuntu1~14.04) 4.8.4"
	.section	.note.GNU-stack,"",@progbits

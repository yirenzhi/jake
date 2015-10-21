	.file	"example.c"
	.section	.rodata
.LC0:
	.string	"please input string:"
.LC1:
	.string	"%s"
.LC2:
	.string	"the copy string is:%s\n"
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
	pushq	%rbx
	subq	$120, %rsp
	.cfi_offset 3, -24
	movq	%fs:40, %rax
	movq	%rax, -24(%rbp)
	xorl	%eax, %eax
	movl	$.LC0, %edi
	call	puts
	leaq	-112(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC1, %edi
	movl	$0, %eax
	call	__isoc99_scanf
	movl	$0, -116(%rbp)
	jmp	.L2
.L3:
	movl	-116(%rbp), %eax
	cltq
	movzbl	-112(%rbp,%rax), %edx
	movl	-116(%rbp), %eax
	cltq
	movb	%dl, -64(%rbp,%rax)
	addl	$1, -116(%rbp)
.L2:
	movl	-116(%rbp), %eax
	movslq	%eax, %rbx
	leaq	-112(%rbp), %rax
	movq	%rax, %rdi
	call	strlen
	cmpq	%rax, %rbx
	jbe	.L3
	leaq	-64(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC2, %edi
	movl	$0, %eax
	call	printf
	movl	$0, %eax
	movq	-24(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L5
	call	__stack_chk_fail
.L5:
	addq	$120, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 4.8.4-2ubuntu1~14.04) 4.8.4"
	.section	.note.GNU-stack,"",@progbits

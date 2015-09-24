	.section	__TEXT,__text,regular,pure_instructions
	.globl	__Z3addii
	.align	4, 0x90
__Z3addii:                              ## @_Z3addii
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp2:
	.cfi_def_cfa_offset 16
Ltmp3:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp4:
	.cfi_def_cfa_register %rbp
	addl	%esi, %edi
	movl	%edi, %eax
	popq	%rbp
	ret
	.cfi_endproc

	.globl	__Z1fi
	.align	4, 0x90
__Z1fi:                                 ## @_Z1fi
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp7:
	.cfi_def_cfa_offset 16
Ltmp8:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp9:
	.cfi_def_cfa_register %rbp
	leal	3(%rdi), %eax
	popq	%rbp
	ret
	.cfi_endproc


.subsections_via_symbols

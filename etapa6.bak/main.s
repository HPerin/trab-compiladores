	.file	"main.c"
	.intel_syntax noprefix
# GNU C11 (GCC) version 5.2.0 (x86_64-unknown-linux-gnu)
#	compiled by GNU C version 5.2.0, GMP version 6.0.0, MPFR version 3.1.3-p4, MPC version 1.0.3
# warning: GMP header version 6.0.0 differs from library version 6.1.0.
# GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
# options passed:  -imultilib . main.c -m32 -masm=intel -mtune=generic
# -march=x86-64 -O0 -fverbose-asm
# options enabled:  -faggressive-loop-optimizations
# -fasynchronous-unwind-tables -fauto-inc-dec -fchkp-check-incomplete-type
# -fchkp-check-read -fchkp-check-write -fchkp-instrument-calls
# -fchkp-narrow-bounds -fchkp-optimize -fchkp-store-bounds
# -fchkp-use-static-bounds -fchkp-use-static-const-bounds
# -fchkp-use-wrappers -fcommon -fdelete-null-pointer-checks
# -fdwarf2-cfi-asm -fearly-inlining -feliminate-unused-debug-types
# -ffunction-cse -fgcse-lm -fgnu-runtime -fgnu-unique -fident
# -finline-atomics -fira-hoist-pressure -fira-share-save-slots
# -fira-share-spill-slots -fivopts -fkeep-static-consts
# -fleading-underscore -flifetime-dse -flto-odr-type-merging -fmath-errno
# -fmerge-debug-strings -fpcc-struct-return -fpeephole
# -fprefetch-loop-arrays -fsched-critical-path-heuristic
# -fsched-dep-count-heuristic -fsched-group-heuristic -fsched-interblock
# -fsched-last-insn-heuristic -fsched-rank-heuristic -fsched-spec
# -fsched-spec-insn-heuristic -fsched-stalled-insns-dep -fschedule-fusion
# -fsemantic-interposition -fshow-column -fsigned-zeros
# -fsplit-ivs-in-unroller -fstdarg-opt -fstrict-volatile-bitfields
# -fsync-libcalls -ftrapping-math -ftree-coalesce-vars -ftree-cselim
# -ftree-forwprop -ftree-loop-if-convert -ftree-loop-im -ftree-loop-ivcanon
# -ftree-loop-optimize -ftree-parallelize-loops= -ftree-phiprop
# -ftree-reassoc -ftree-scev-cprop -funit-at-a-time -funwind-tables
# -fverbose-asm -fzero-initialized-in-bss -m32 -m80387 -m96bit-long-double
# -malign-stringops -mavx256-split-unaligned-load
# -mavx256-split-unaligned-store -mfancy-math-387 -mfp-ret-in-387 -mfxsr
# -mglibc -mieee-fp -mlong-double-80 -mmmx -mno-red-zone -mno-sse4
# -mpush-args -msahf -msse -msse2 -mtls-direct-seg-refs -mvzeroupper

	.comm	hash_map,4,4
	.section	.rodata
.LC0:
	.string	"-----------------"
	.align 4
.LC1:
	.string	"Usage: etapa3 <input> <output>"
.LC2:
	.string	"r"
	.align 4
.LC3:
	.string	"Error opening input file: %s !\n"
.LC4:
	.string	"w"
	.align 4
.LC5:
	.string	"Erro opening output file: %s !\n"
.LC6:
	.string	"Started!"
	.align 4
.LC7:
	.string	"Failed! Semantic errors found."
.LC8:
	.string	"Success!"
	.text
	.globl	main
	.type	main, @function
main:
.LFB2:
	.cfi_startproc
	lea	ecx, [esp+4]	#,
	.cfi_def_cfa 1, 0
	and	esp, -16	#,
	push	DWORD PTR [ecx-4]	#
	push	ebp	#
	.cfi_escape 0x10,0x5,0x2,0x75,0
	mov	ebp, esp	#,
	push	ebx	#
	push	ecx	#
	.cfi_escape 0xf,0x3,0x75,0x78,0x6
	.cfi_escape 0x10,0x3,0x2,0x75,0x7c
	sub	esp, 16	#,
	mov	ebx, ecx	# tmp104,
	cmp	DWORD PTR [ebx], 3	# argc,
	je	.L2	#,
	sub	esp, 12	#,
	push	OFFSET FLAT:.LC0	#
	call	puts	#
	add	esp, 16	#,
	sub	esp, 12	#,
	push	OFFSET FLAT:.LC1	#
	call	puts	#
	add	esp, 16	#,
	sub	esp, 12	#,
	push	OFFSET FLAT:.LC0	#
	call	puts	#
	add	esp, 16	#,
	sub	esp, 12	#,
	push	1	#
	call	exit	#
.L2:
	call	initMe	#
	mov	eax, DWORD PTR [ebx+4]	# tmp97, argv
	add	eax, 4	# D.3789,
	mov	eax, DWORD PTR [eax]	# D.3790, *_5
	sub	esp, 8	#,
	push	OFFSET FLAT:.LC2	#
	push	eax	# D.3790
	call	fopen	#
	add	esp, 16	#,
	mov	DWORD PTR [ebp-12], eax	# input, tmp98
	cmp	DWORD PTR [ebp-12], 0	# input,
	jne	.L3	#,
	sub	esp, 12	#,
	push	OFFSET FLAT:.LC0	#
	call	puts	#
	add	esp, 16	#,
	mov	eax, DWORD PTR [ebx+4]	# tmp99, argv
	add	eax, 4	# D.3789,
	mov	eax, DWORD PTR [eax]	# D.3790, *_33
	sub	esp, 8	#,
	push	eax	# D.3790
	push	OFFSET FLAT:.LC3	#
	call	printf	#
	add	esp, 16	#,
	sub	esp, 12	#,
	push	OFFSET FLAT:.LC0	#
	call	puts	#
	add	esp, 16	#,
	sub	esp, 12	#,
	push	2	#
	call	exit	#
.L3:
	mov	eax, DWORD PTR [ebx+4]	# tmp100, argv
	add	eax, 8	# D.3789,
	mov	eax, DWORD PTR [eax]	# D.3790, *_9
	sub	esp, 8	#,
	push	OFFSET FLAT:.LC4	#
	push	eax	# D.3790
	call	fopen	#
	add	esp, 16	#,
	mov	DWORD PTR [ebp-16], eax	# output, tmp101
	cmp	DWORD PTR [ebp-16], 0	# output,
	jne	.L4	#,
	sub	esp, 12	#,
	push	OFFSET FLAT:.LC0	#
	call	puts	#
	add	esp, 16	#,
	mov	eax, DWORD PTR [ebx+4]	# tmp102, argv
	add	eax, 8	# D.3789,
	mov	eax, DWORD PTR [eax]	# D.3790, *_27
	sub	esp, 8	#,
	push	eax	# D.3790
	push	OFFSET FLAT:.LC5	#
	call	printf	#
	add	esp, 16	#,
	sub	esp, 12	#,
	push	OFFSET FLAT:.LC0	#
	call	puts	#
	add	esp, 16	#,
	sub	esp, 12	#,
	push	2	#
	call	exit	#
.L4:
	mov	eax, DWORD PTR [ebp-12]	# tmp103, input
	mov	DWORD PTR yyin, eax	# yyin, tmp103
	sub	esp, 12	#,
	push	DWORD PTR [ebp-16]	# output
	call	setoutput	#
	add	esp, 16	#,
	sub	esp, 12	#,
	push	OFFSET FLAT:.LC0	#
	call	puts	#
	add	esp, 16	#,
	sub	esp, 12	#,
	push	OFFSET FLAT:.LC6	#
	call	puts	#
	add	esp, 16	#,
	call	yyparse	#
	call	hasSemanticErrors	#
	test	eax, eax	# D.3791
	je	.L5	#,
	sub	esp, 12	#,
	push	OFFSET FLAT:.LC7	#
	call	puts	#
	add	esp, 16	#,
	sub	esp, 12	#,
	push	OFFSET FLAT:.LC0	#
	call	puts	#
	add	esp, 16	#,
	sub	esp, 12	#,
	push	4	#
	call	exit	#
.L5:
	sub	esp, 12	#,
	push	OFFSET FLAT:.LC8	#
	call	puts	#
	add	esp, 16	#,
	sub	esp, 12	#,
	push	OFFSET FLAT:.LC0	#
	call	puts	#
	add	esp, 16	#,
	sub	esp, 12	#,
	push	0	#
	call	exit	#
	.cfi_endproc
.LFE2:
	.size	main, .-main
	.ident	"GCC: (GNU) 5.2.0"
	.section	.note.GNU-stack,"",@progbits

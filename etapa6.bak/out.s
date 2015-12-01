	.intel_syntax noprefix
	.text
	.globl v
	.align 4
	.type v, @object
	.size v, 40
v:
	.long 0
	.long 0
	.long 0
	.long 0
	.long 0
	.zero 40
a:
	.long 0
r:
	.long 0
	.globl main
	.type main, @function
main:
	.comm _temp_n1000,4
	mov eax, DWORD PTR _temp_n1000
	mov DWORD PTR a, eax
	mov eax, DWORD PTR a
	pop ebp
	ret


	mov eax, 0
	pop ebp
	ret



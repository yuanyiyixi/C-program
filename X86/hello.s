#.section .data
.LC0:
	.string "hello world\n"
	.text
.globl _start
_start:

	movl $4, %eax
	movl $1, %ebx
	movl $.LC0, %ecx
	movl $12, %edx
#	int  $0x80

	movl $1, %eax
	movl $0, %ebx
	int  $0x80

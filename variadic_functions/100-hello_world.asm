segment .data
	message db 'Hello, World', 0xa

segment .text
	global main

main:
	mov rdx, 13
	mov rsi, message
	mov rdi, 1
	mov rax, 1
	syscall

	mov rax, 60
	mov rdi, 0
	syscall
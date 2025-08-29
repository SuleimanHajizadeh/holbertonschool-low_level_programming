; 100-hello_world.asm
; Prints "Hello, World\n" using the write syscall

section .data
msg     db "Hello, World", 10   ; string + newline
len     equ $ - msg             ; length of the string

section .text
global _start

_start:
    mov rax, 1          ; sys_write
    mov rdi, 1          ; file descriptor: stdout
    mov rsi, msg        ; address of the string
    mov rdx, len        ; length of the string
    syscall             ; invoke system call

    mov rax, 60         ; sys_exit
    xor rdi, rdi        ; exit code 0
    syscall

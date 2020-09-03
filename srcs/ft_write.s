section .text
extern __errno_location
global ft_write

ft_write:
	push rbx
    mov rax, 0x01
    syscall
    test rax, rax
    jnl _end

_error:
    neg rax
    mov rbx, rax
    call __errno_location
    mov [rax], rbx
    mov rax, -1
_end:
	pop rbx
    ret
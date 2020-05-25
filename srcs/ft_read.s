section .text
extern __errno_location
global ft_read

ft_read:
    mov rax, 0x00
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
    ret
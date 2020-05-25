section .text
extern __errno_location, malloc, ft_strlen, ft_strcpy
global ft_strdup

ft_strdup:
    call ft_strlen
    push rdi
    mov rdi, rax
    call malloc
    test rax, rax
    jz  _error
    jmp _end

_error:
    neg rax
    mov rbx, rax
    call __errno_location
    mov [rax], rbx
    mov rax, -1
_end:
    pop rdi
    mov rsi, rdi
    mov rdi, rax
    call ft_strcpy
    ret
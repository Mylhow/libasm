section .text
extern __errno_location, malloc, ft_strlen, ft_strcpy
global ft_strdup

ft_strdup:
    push rbx
    push rdi
    call ft_strlen
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
    push rdi
    mov rdi, rax
    call ft_strcpy
    pop rdi
    pop rbx
    ret
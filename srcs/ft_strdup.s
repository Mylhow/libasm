section .text
extern __errno_location, malloc, ft_strlen, ft_strcpy
global ft_strdup

ft_strdup:
    call ft_strlen
    push rdi
    inc rax
    mov rdi, rax
    call malloc
    pop rdi
    cmp rax, 0
    jz  _error
    jmp _end

_error:
    call __errno_location
    xor rax, rax
_end:
    push rdi
	push rsi
    mov rsi, rdi
    mov rdi, rax
    call ft_strcpy
    pop rdi
    pop rsi
    ret
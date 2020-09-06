section .text
extern malloc, ft_strlen, ft_strcpy
global ft_strdup

ft_strdup:
    push rdi
    call ft_strlen
    inc rax
    mov rdi, rax
    call malloc
    pop rdi
    cmp rax, 0
    je  _error
    jmp _end

_error:
    mov rax, 0
    ret

_end:
    push rdi
	push rsi
    mov rsi, rdi
    mov rdi, rax
    call ft_strcpy
    pop rdi
    pop rsi
    ret
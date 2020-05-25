section .text
global ft_strcpy

ft_strcpy:
    xor rcx, rcx

_loop:
    mov dl, byte [rsi + rcx]
    mov byte [rdi + rcx], dl
    cmp dl, 0
    je _end
    inc rcx
    jmp _loop

_end:
    mov rax, rdi
    ret
section .text
global ft_strlen

ft_strlen:
    xor rcx, rcx
_loop:
    mov sil, [rdi + rcx]
    cmp sil, 0
    je _end
    inc rcx
    jmp _loop
_end:
    mov rax, rcx
    ret
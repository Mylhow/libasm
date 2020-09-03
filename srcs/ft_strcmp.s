section .txt
global ft_strcmp

ft_strcmp:
    xor rcx, rcx

_loop:
    mov r10b, byte [rdi + rcx]
    mov r11b, byte [rsi + rcx]
    inc rcx
    cmp r10b, r11b
    jne _end
    cmp r10b, 0
    je _end
    cmp r11b, 0
    je _end
    jmp _loop
    
_end:
    movzx r10, r10b
    movzx r11, r11b
    sub r10, r11
    mov rax, r10
    ret
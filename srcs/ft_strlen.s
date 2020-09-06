section .text
global ft_strlen

ft_strlen:
    xor rcx, rcx
    jmp _loop

_incr:
	inc rcx

_loop:
    cmp byte [rdi + rcx], 0
    jne _incr

_end:
	mov rax, rcx
    ret
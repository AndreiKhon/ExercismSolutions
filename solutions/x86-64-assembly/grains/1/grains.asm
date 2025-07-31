section .text
global square
square:
    cmp rdi, 0
    je exceptional
    js exceptional
    cmp rdi, 65
    jge exceptional
    mov rax, 1
    dec rdi
    mov cl, dil
    shl rax, cl
    ret
exceptional:
    xor rax, rax
    ret


global total
total:
    mov rax, 18446744073709551615
    ret

%ifidn __OUTPUT_FORMAT__,elf64
section .note.GNU-stack noalloc noexec nowrite progbits
%endif

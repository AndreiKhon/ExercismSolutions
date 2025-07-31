section .text
global leap_year
leap_year:
    mov rax, rdi
    mov rcx, 4
    mov rdx, 0
    div rcx
    cmp rdx, 0
    jz div_100
    jmp false
div_100:
    mov rax, rdi
    mov rcx, 100
    mov rdx, 0
    div rcx
    cmp rdx, 0
    jz div_400
    jmp true
div_400:
    mov rax, rdi
    mov rcx, 400
    mov rdx, 0
    div rcx
    cmp rdx, 0
    jz true
    jmp false
true:
    mov rax, 1
    ret
false:
    mov rax, 0
    ret


%ifidn __OUTPUT_FORMAT__,elf64
section .note.GNU-stack noalloc noexec nowrite progbits
%endif

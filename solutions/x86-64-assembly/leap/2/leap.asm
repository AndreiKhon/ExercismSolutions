section .text
global leap_year
leap_year:
    mov rcx, 4
    call divisible
    jnz false
    mov rcx, 100
    call divisible
    jnz true
    mov rcx, 400
    call divisible
    jnz false
true:
    mov rax, 1
    ret
false:
    mov rax, 0
    ret
divisible:
    mov rax, rdi
    xor rdx, rdx
    div rcx
    test rdx, rdx
    ret

%ifidn __OUTPUT_FORMAT__,elf64
section .note.GNU-stack noalloc noexec nowrite progbits
%endif

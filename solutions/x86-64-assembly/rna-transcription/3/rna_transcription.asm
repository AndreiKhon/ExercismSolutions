default rel
section .rodata
nucleotides: db "CGAU"

section .text
global to_rna
to_rna:
    lea rbx, [nucleotides]
    xchg rsi, rdi
loop:
    xor edx, edx
    lodsb

    cmp al, 'G'
    cmove edx, [rbx + 0]

    cmp al, 'C'
    cmove edx, [rbx + 1]

    cmp al, 'T'
    cmove edx, [rbx + 2]

    cmp al, 'A'
    cmove edx, [rbx + 3]

    mov eax, edx
    stosb

    test al, al
    jnz loop
end_loop:
    ret

%ifidn __OUTPUT_FORMAT__,elf64
section .note.GNU-stack noalloc noexec nowrite progbits
%endif

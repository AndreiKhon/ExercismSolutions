default rel
section .data
g: db "G", 0
c: db "C", 0
a: db "A", 0
u: db "U", 0

section .text
global to_rna
to_rna:
loop:
    mov dl, byte [rdi]
    cmp byte [rdi], 0x00
    je end_loop

    cmp byte [rdi], 'G'
    cmove dx, word [c]

    cmp byte [rdi], 'C'
    cmove dx, word [g]

    cmp byte [rdi], 'T'
    cmove dx, word [a]

    cmp byte [rdi], 'A'
    cmove dx, word [u]

    mov byte [rsi], dl
    inc rsi
    inc rdi
    jmp loop
end_loop:
    mov byte [rsi], 0x00
    ret

%ifidn __OUTPUT_FORMAT__,elf64
section .note.GNU-stack noalloc noexec nowrite progbits
%endif

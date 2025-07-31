default rel
section .data
g: db "G", 0
c: db "C", 0
t: db "T", 0
a: db "A", 0
u: db "U", 0

section .text
global to_rna
to_rna:
    mov rbx, rdi
    mov rdi, rsi
    ;rax - result of nucleotide processing, rbx - original rna, rdx(dl) - byte to compare with, rsi - input adress to copy from, rdi output address
loop:
    cmp byte [rbx], 0x00
    je end_loop

    mov dl, byte [g]
    lea rsi, [c]
    call process_nucleotide
    test rax, rax
    jnz loop

    mov dl, byte [c]
    lea rsi, [g]
    call process_nucleotide
    test rax, rax
    jnz loop

    mov dl, byte [t]
    lea rsi, [a]
    call process_nucleotide
    test rax, rax
    jnz loop

    mov dl, byte [a]
    lea rsi, [u]
    call process_nucleotide
    jmp loop
end_loop:
    mov byte [rdi], 0x00
    ret

process_nucleotide:
    cmp byte [rbx], dl
    jne process_return

    movsb
    inc rbx

    mov rax, 1
    ret
process_return:
    xor rax, rax
    ret


%ifidn __OUTPUT_FORMAT__,elf64
section .note.GNU-stack noalloc noexec nowrite progbits
%endif

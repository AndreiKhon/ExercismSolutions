section .text
global can_create
can_create:
    xor rax, rax
    cmp rdi, 0
    jl .false_create
    cmp rdi, 7
    jg .false_create
    cmp rsi, 0
    jl .false_create
    cmp rsi, 7
    jg .false_create

    mov rax, 1
.false_create:
    ret

global can_attack
can_attack:
    mov rax, 1
    sub rdi, rdx
    test rdi, rdi
    jz .true_attack
    sub rsi, rcx
    test rsi, rsi
    jz .true_attack
    cmp rdi, rsi
    je .true_attack
    add rdi, rsi
    jz .true_attack
    xor rax, rax
.true_attack:
    ret


%ifidn __OUTPUT_FORMAT__,elf64
section .note.GNU-stack noalloc noexec nowrite progbits
%endif

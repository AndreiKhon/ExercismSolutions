section .text
global can_create
can_create:
    cmp rdi, 0
    jl .false_create
    cmp rdi, 7
    jg .false_create
    cmp rsi, 0
    jl .false_create
    cmp rsi, 7
    jg .false_create

    mov rax, 1
    ret
.false_create:
    xor rax, rax
    ret

global can_attack
can_attack:
    cmp rdi, rdx
    jle .next_swap
    xchg rdi, rdx
.next_swap:
    cmp rsi, rcx
    jle .main_check
    xchg rsi, rcx
.main_check:
    sub rdi, rdx
    test rdi, rdi
    jz .true_attack
    sub rsi, rcx
    test rsi, rsi
    jz .true_attack
    sub rdi, rsi
    test rdi, rdi
    jz .true_attack
    xor rax, rax
    ret
.true_attack:
    mov rax, 1
    ret


%ifidn __OUTPUT_FORMAT__,elf64
section .note.GNU-stack noalloc noexec nowrite progbits
%endif

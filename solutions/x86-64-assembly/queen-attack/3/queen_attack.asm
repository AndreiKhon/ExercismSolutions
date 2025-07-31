section .text
global can_create
can_create:
    xor rax, rax
    or rdi, rsi
    shr rdi, 3
    setz al
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

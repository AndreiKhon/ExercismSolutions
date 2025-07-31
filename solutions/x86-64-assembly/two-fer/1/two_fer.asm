default rel
section .data
start_str: db "One for ", 0
no_name: db "you", 0
end_str: db ", one for me.", 0

section .text
global two_fer
two_fer:
    ; rdi first arg, rsi the second

    mov rax, rsi    ; buffer address
    mov rbx, rdi    ; name address

    mov rdi, rax            ; dest
    lea rsi, [start_str]    ; src
    call copy_string

    test rbx, rbx
    jnz named

    mov rdi, rax            ; dest
    lea rsi, [no_name]      ; src
    call copy_string

    jmp end
named:
    mov rdi, rax            ; dest
    lea rsi, [rbx]          ; src
    call copy_string
end:
    mov rdi, rax            ; dest
    lea rsi, [end_str]      ; src
    call copy_string
copy_string:
    cmp byte [rsi], 0x00
    jz return
    mov rcx, [rsi]
    mov [rdi], rcx
    inc rsi
    inc rdi
    jmp copy_string
return:
    mov rax, rdi
    ret
    
    

%ifidn __OUTPUT_FORMAT__,elf64
section .note.GNU-stack noalloc noexec nowrite progbits
%endif

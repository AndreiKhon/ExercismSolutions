section .text
global rotate
rotate:
    mov rbx, rdx ; rbx - output buffer
    xor rdx, rdx ; rdx(dl) will keep encrypted character
    ; rdi - original string
    ; rsi - rot key
loop:
    cmp byte [rdi], 0x00
    je end_loop

    mov dl, byte [rdi]
    inc rdi
    call is_alpha
    test rax, rax
    jz no_rotate
    
    call calculate_rotation
no_rotate:
    mov [rbx], dl
    inc rbx
    jmp loop
end_loop:
    mov byte [rbx], 0x00
    ret



is_lower:
    cmp dl, 'a'
    jl false_lower
    cmp dl, 'z'
    jg false_lower
true_lower:
    mov rax, 1
    ret
false_lower:
    xor rax, rax
    ret



is_upper:
    cmp dl, 'A'
    jl false_upper
    cmp dl, 'Z'
    jg false_upper
true_upper:
    mov rax, 1
    ret
false_upper:
    xor rax, rax
    ret    



is_alpha:
    call is_lower
    test rax, rax
    jnz true_alpha
    call is_upper
true_alpha:
    ret



calculate_rotation:
    ; Encrypted symbol will be set in rdx(dl)

    mov r8, 'a'
    call is_lower
    test rax, rax
    cmovnz r9, r8

    mov r8, 'A'
    cmovz r9, r8

    sub rdx, r9
    add rdx, rsi
    mov rax, rdx
    xor rdx, rdx
    mov rcx, 26
    div rcx
    add rdx, r9
    ret

%ifidn __OUTPUT_FORMAT__,elf64
section .note.GNU-stack noalloc noexec nowrite progbits
%endif

section .text
global rotate
rotate:
    mov rbx, rdx ; rbx - output buffer
    xor edx, edx ; rdx(dl) will keep encrypted character
    ; rdi - original string
    ; rsi - rot key
loop:
    mov dl, byte [rdi]
    inc rdi
    call is_alpha
    test al, al
    jz no_rotate
    
    call calculate_rotation
no_rotate:
    mov [rbx], dl
    inc rbx
    test dl, dl
    jnz loop
end_loop:
    ret



is_alpha:
    mov al, dl
    or al, 'a' - 'A' ; 'a' - 'A' <==> 0x20 <==> 0b 0010 0000

    cmp al, 'a'
    jl false_alpha
    cmp al, 'z'
    jle true_alpha
false_alpha:
    xor eax, eax
true_alpha:
    ret



calculate_rotation:
    ; Encrypted symbol will be set in rdx(dl)
    ; ['A':'Z'] <==> [0x41:0x5A] ; ['a':'z'] <==> [0x61:0x7A]
    ; 0x60 <==> 0b 0110 0000
    ; 0x40 <==> 0b 0100 0000
    ; 0x20 <==> 0b 0010 0000
    mov cl, dl
    and cl, 'a' - 1  ; 'a' - 1 <==> 0x60, now cl set with 'A' - 1 or 'a' - 1 depends on caseness
    sub dl, cl       ; now 1..26
    add dl, sil      ; now 1..26 + key (0..26) = 1..52
    cmp dl, 26
    jle .ok
    sub dl, 26       ; now (27..52) - 26 = 1..26
.ok:
    add dl, cl       ; add back 'caseness' bits
    ret

%ifidn __OUTPUT_FORMAT__,elf64
section .note.GNU-stack noalloc noexec nowrite progbits
%endif

default rel
section .data
start_str: db "One for ", 0
no_name: db "you", 0
end_str: db ", one for me.", 0

section .text
global two_fer
two_fer:
    mov rbx, rdi    ; name address
    mov rdi, rsi    ; buffer address

    lea rsi, [start_str]    ; src
    call copy_string

    lea rsi, [no_name]      ; src ; default name
    test rbx, rbx
    cmovnz rsi, rbx         ; src ; provided name
    call copy_string

    lea rsi, [end_str]      ; src
    ; call copy_string ; [[fallthrough]]
copy_string:
    cmp byte [rsi], 0x00
    movsb
    jnz copy_string
    dec rdi
    ret
    
    

%ifidn __OUTPUT_FORMAT__,elf64
section .note.GNU-stack noalloc noexec nowrite progbits
%endif

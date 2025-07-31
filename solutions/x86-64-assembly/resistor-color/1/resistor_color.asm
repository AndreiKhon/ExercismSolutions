default rel

section .data
black: db "black", 0
brown: db "brown", 0
red: db "red", 0
orange: db "orange", 0
yellow: db "yellow", 0
green: db "green", 0
blue: db "blue", 0
violet: db "violet", 0
grey: db "grey", 0
white: db "white", 0
all_colors: dq black, brown, red, orange, yellow, green, blue, violet, grey, white, 0
all_colors_size: dq ($ - all_colors)

section .text
global color_code
color_code:
    mov rbx, rdi 

    mov rcx, 0
    lea rdx, [all_colors]
loop:
    cmp rcx, 10
    je color_return
    mov rsi, [rdx + rcx * 8]
    mov rdi, rbx
    call cmp_color
    test rax, rax
    jnz color_return
    inc rcx
    jmp loop
color_return:
    mov rax, rcx
    ret


cmp_color:
    cmpsb
    jne cmp_false
cmp_while:
    cmp byte [rsi], 0x00
    je cmp_true
    cmpsb
    je cmp_while
cmp_false:
    xor rax, rax
    ret
cmp_true:
    mov rax, 1
    ret


global colors
colors:
    lea rax, [all_colors]
    ret


%ifidn __OUTPUT_FORMAT__,elf64
section .note.GNU-stack noalloc noexec nowrite progbits
%endif

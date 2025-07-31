default rel

section .text
global reverse
reverse:
  mov r8, rdi
  xor rax, rax
  xor rcx, rcx
  not rcx

  repne scasb
  not rcx
  ; now we have string size in rcx
  sub rcx, 2
  
swap:
  cmp rax, rcx
  jge return
  mov bl, [r8 + rax]
  mov dl, [r8 + rcx]
  mov [r8 + rax], dl
  mov [r8 + rcx], bl
  inc eax
  dec ecx
  jmp swap
return:
  ret

%ifidn __OUTPUT_FORMAT__,elf64
section .note.GNU-stack noalloc noexec nowrite progbits
%endif

default rel

section .text
global reverse
reverse:
  mov r8, rdi
  xor eax, eax
  xor ecx, ecx
  not ecx

  repne scasb
  not ecx
  ; now we have string size + 1 in rcx ; rcx <==> size + 1
  sub ecx, 2
  ; rcx <==> size - 1
  
  jmp .compare
  
.swap:
  mov bl, [r8 + rax]
  mov dl, [r8 + rcx]
  mov [r8 + rax], dl
  mov [r8 + rcx], bl
  inc eax
  dec ecx
.compare:
  cmp eax, ecx
  jl .swap
  ret

%ifidn __OUTPUT_FORMAT__,elf64
section .note.GNU-stack noalloc noexec nowrite progbits
%endif

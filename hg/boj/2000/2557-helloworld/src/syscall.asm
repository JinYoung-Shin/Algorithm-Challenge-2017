M: db "Hello World!"
section .text
global main
main:
    mov edx, 12
    mov ecx, M
    mov ebx, 1
    mov eax, 4
    int 0x80
    ret
extern printf
section .data
    Str : db "Hello World!",0
        
section .text
    global main
main:
    push Str
    call printf
    add esp, 4
ret
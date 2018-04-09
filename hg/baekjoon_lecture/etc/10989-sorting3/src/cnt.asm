[BITS 32]

extern printf
extern scanf
SECTION .data

SCANF_FORMATSTRING: db "%d", 0
PRINTF_FORMATSTRING: db "%d",0xa, 0

arr:
    times 100001 dd 0x0 ; declare int arr[100001];
N: 
    dd 0x0 ; int N
tmp:
    dd 0x0 ; int tmp


SECTION .text
    global main

main:
    push N
    push SCANF_FORMATSTRING
    call scanf
    add esp, 8 ; scanf("%d", &N);
    
    mov ecx, DWORD [ N ]
    
.GET_SCAN_LOOP:
    push ecx ; save ecx register before function call
    push tmp
    push SCANF_FORMATSTRING
    call scanf
    add esp, 8
    pop ecx ; scanf("%d", &tmp);

    mov edi, DWORD [ tmp ] ; offset
    mov eax, DWORD [ arr + edi ] ; prev value
    add eax, 1
    mov DWORD[ arr + edi ], eax ; arr[tmp]++
    
    loop .GET_SCAN_LOOP

    mov ecx, 1; ecx = i
.PRINT_OUT_LOOP:
    mov eax, DWORD [ arr + ecx ]; eax = arr[i]
    cmp eax, 0
    je .LOOP_EPILOGUE ; arr[i] == 0
    push ecx
    push eax
    
    push ecx
    push PRINTF_FORMATSTRING
    call printf
    add esp, 8
    
    pop eax
    pop ecx ; printf("%d\n", i);
    
    sub eax, 1
    mov DWORD [ arr + ecx ], eax
    
    ; jmp .PRINT_OUT_LOOP
    
    
.LOOP_EPILOGUE:
    add ecx, 1
    cmp ecx, 10000
    jle .PRINT_OUT_LOOP ; outer for loop
    
    ;;;;;;;;;;;;;
    ; push DWORD [ N ]
    ; push PRINTF_FORMATSTRING
    ; call printf
    ; add esp, 8 ; printf("%d\n", N);
    
ret
    
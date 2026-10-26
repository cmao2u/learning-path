data segment
    num1 dw 12
    num2 dw 34
data ends

stackseg segment stack
    db 128 dup(0)
stackseg ends

code segment
    assume cs:code, ds:data

start:
    mov ax, data
    mov ds, ax

    mov ax, num1
    mov bx, num2
    mov num1, bx
    mov num2, ax

    mov ax, 4c00h
    int 21h

code ends
end start
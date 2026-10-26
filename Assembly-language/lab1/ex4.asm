data segment
    arr db 10, 20, 30, 40, 50
    backup db 0
data ends

stackseg segment stack
    db 128 dup(0)
stackseg ends

code segment
    assume cs:code, ds:data

start:
    mov ax, data
    mov ds, ax

    mov al, arr+2
    mov backup, al

    mov ax, 4c00h
    int 21h

code ends
end start
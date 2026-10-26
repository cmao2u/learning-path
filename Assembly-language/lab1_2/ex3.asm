data segment
    value32 dd 12345678h
data ends

stackseg segment stack
    db 128 dup(0)
stackseg ends

code segment
    assume cs:code, ds:data

start:
    mov ax, data
    mov ds, ax

    mov ax, word ptr value32+2
    mov dx, word ptr value32

    mov ax, 4c00h
    int 21h

code ends
end start
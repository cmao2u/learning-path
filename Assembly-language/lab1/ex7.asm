data segment
    maskValue dw 0FFFFh
data ends

stackseg segment stack
    db 128 dup(0)
stackseg ends

code segment
    assume cs:code, ds:data

start:
    mov ax, data
    mov ds, ax

    and maskValue, 0007h

    mov ax, 4c00h
    int 21h

code ends
end start
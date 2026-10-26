data segment
    initialValue dw 1234h
data ends

stackseg segment stack
    db 128 dup(0)
stackseg ends

code segment
    assume cs:code, ds:data

start:
    mov ax, data
    mov ds, ax

    mov ax, initialValue
    xchg ah, al

    mov ax, 4c00h
    int 21h

code ends
end start
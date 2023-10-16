; Question-3 (a)
include irvine32.inc
.data
array word 500h, 1000h, 1500h, 2000h
.code
mov si, offset array
mov ax, [si]
add si, 2
mov ax, [si]
add si, 2
mov ax, [si]
add si, 2
mov ax, [si]
exit
main endp
end main
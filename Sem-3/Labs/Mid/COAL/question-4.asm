; Question-3 (b)
include irvine32.inc
.data
mode1 byte 99, 89, 67, 44
mode2 byte 4dup(?)
.code
mov si, offset mode1
mov di, [mode + 3]
mov ecx, lengthof mode1
revLoop:
mov [di], [si]
inc si
dec di
dec ecx
jnz revLoop
exit
main endp
end main
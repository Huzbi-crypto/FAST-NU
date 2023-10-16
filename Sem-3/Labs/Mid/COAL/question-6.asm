; Question-4 (b)
include irvine32.inc
.data
b dword 6, 3, 0, 4, 1
temp dword (?)
.code
mov esi, offset b
mov temp, [esi]
mov [esi], [esi + 8]
mov [esi + 8], temp ; 0, 3, 6, 4, 1
mov esi, offset b
mov temp, [esi + 4]
mov [esi + 4], [esi + 16]
mov [esi + 16], temp ; 0, 1, 6, 4, 3
mov esi, offset b
mov temp, [esi + 8]
mov [esi + 8], [esi + 16]
mov [esi + 16], temp ; 0, 1, 3, 4, 6
call dumpregs
exit
main endp
end main
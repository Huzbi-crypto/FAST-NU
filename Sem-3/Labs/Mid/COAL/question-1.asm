; Question-1 (b)
include irvine32.inc
.code
main proc
mov eax, 23
add eax, 110100b
add eax, 46h
add eax, 89o
add eax, 10100b
call writeint
mov eax, 29o
add eax, -22h
add eax, -89d
add eax, 110001b
add eax, -34h
call writeint
exit
main endp
end main
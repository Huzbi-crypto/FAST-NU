; Question-2 (b)
include irvine32.inc
.data
x byte 10h
y byte 15h
z byte 20h
s byte 30h
.code
mov eax, x
add eax, y
mov ebx, x
add ebx, -y
sub eax, ebx
add eax, z
add eax, s
exit
main endp
end main
; Question-5 (a)
include irvine32.inc
.data
i word 1
.code
mov ecx, 20
print:
mov eax, i
call writeint
mov al, &quot; &quot;
call writechar
dec ecx
inc i
jnz print
exit
main endp
end main
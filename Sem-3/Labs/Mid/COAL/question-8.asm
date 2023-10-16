include irvine32.inc
.data
i byte 5
.code
mov ecx, i
outer:
inner:
mov al, "@";
call writechar
dec ecx
jnz inner
call crlf
dec i
mov ecx, i
jnz outer
mov i, 2
mov ecx, i
outer:
inner:
mov al, "@";
call writechar
mov al, " ";
call writechar
dec ecx
jnz inner
call crlf
inc i
mov ecx, i
jl outer
exit
main endp
end main
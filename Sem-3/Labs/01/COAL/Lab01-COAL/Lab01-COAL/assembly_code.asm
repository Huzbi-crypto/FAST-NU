;AUTHOR: Huzefa Saifuddin (Huzbi) - 22K-5125
;TITLE: My First Program

include irvine32.inc ;Including Irvine Library

.code
main proc
	
	;Calculations
	mov eax,8500h
	mov ebx,39h
	mov ecx,60h
	add eax,ebx
	add eax,ecx
	mov ebx,85h
	mov ecx,64h
	add eax,ebx
	add eax,ecx

	;Calling Irvine Library function to output register values
	call dumpregs

main endp
end main
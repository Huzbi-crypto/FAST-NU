;Author: Huzefa Saifuddin (Huzbi) - 22K-5125
;TITLE: COAL Lab04

;----------------------------------- QUESTION 4 -----------------------------------
include irvine32.inc

.data

array1 byte 10, 20, 30, 40
array2 byte dup(?)

.code
main proc
	mov eax,array1[3]
	mov array2,eax

	mov eax,array1[2]
	mov array2[1],eax

	mov eax,array1[1]
	mov array2[2],eax

	mov eax,array
	mov array2[3],eax

	call dumpregs

main endp
end main
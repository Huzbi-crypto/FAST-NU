;Author: Huzefa Saifuddin (Huzbi) - 22K-5125
;TITLE: COAL Lab04

;----------------------------------- QUESTION 1 -----------------------------------
include irvine32.inc

.data
	myArray dword 07h, 04h, 01h, 05h, 02h

.code
main proc
	mov	eax,myArray + 8			
	mov	eax,myArray + 16
	mov eax,myArray + 4
	mov eax,myArray + 12
	mov eax,myArray

	call writeint
	call dumpregs

main endp
end main
;Author: Huzefa Saifuddin (Huzbi) - 22K-5125
;TITLE: COAL Lab04

;----------------------------------- QUESTION 2 -----------------------------------
include irvine32.inc

.data
	arrayB byte 10, 20, 30
	arrayW word 150, 250, 350
	arrayD dword 600, 1200, 1800

	;sum1 dword (?)
	;sum2 dword (?)
	;sum3 dword (?)

.code
main proc
	
	mov eax,0
	mov ebx,0
	mov ecx,0

	mov al,arrayB
	add ax,[arrayW]
	add eax,[arrayD]

	mov bl,arrayB[1]
	add bx,arrayW + 2
	add ebx,arrayD + 4

	mov cl,arrayB[2]
	add bx,arrayW + 4
	add ecx,arrayD + 8

	call writeint
	call dumpregs

main endp
end main
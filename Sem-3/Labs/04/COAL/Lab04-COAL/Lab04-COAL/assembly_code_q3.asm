;Author: Huzefa Saifuddin (Huzbi) - 22K-5125
;TITLE: COAL Lab04

;----------------------------------- QUESTION 3 -----------------------------------
include irvine32.inc

.data
	arrayB byte 10,20,30
	arrayW word 150,250,350
	arrayD dword 600,1200,1800

.code
main proc
	mov eax,0
	mov ebx,0
	mov ecx,0

	mov al,arrayB

	add ax,[arrayW]

	add eax,[arrayD]

	mov bl,arrayB[1]

	add bx ,[arrayW+2]

	add ebx, [arrayD+4]

	mov cl,arrayB[2]


	add cx,arrayW[4]

	add ecx,[arrayD+8]

	call dumpregs


	exit

main endp
end main
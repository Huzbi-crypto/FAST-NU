;AUTHOR: Huzefa Saifuddin (Huzbi) - 22K-5125
;TITLE: COAL Lab03

include irvine32.inc

;--------------------------------------- QUESTION 1 ---------------------------------------  
;.data
;val1 sword ?
;val2 sbyte -10d

;.code
;main proc
	
	;mov eax,0
	;mov al,val2

	;call dumpregs

;main endp
;end main

;--------------------------------------- QUESTION 2 ---------------------------------------  
;.data
;val3 sdword -2147483648
;.code
;main proc
	
	;mov eax,0
	;mov al,val2

	;call dumpregs

;main endp
;end main

;--------------------------------------- QUESTION 3 ---------------------------------------  
;.data
;arrayList word 1,2,3,4
;.code
;main proc
	
	;call dumpregs

;main endp
;end main

;--------------------------------------- QUESTION 4 ---------------------------------------  
;.data
;myColor byte 'Blue',0

;a word 12
;b word 2
;d word 8
;e word 14
;f word 13
;.code
;main proc
	
	;call dumpregs

;main endp
;end main

;--------------------------------------- QUESTION 5 ---------------------------------------  
;.data
;a byte 010h
;b byte 015h
;d byte 030h
;e byte 020h
;.code
;main proc
	
	;mov eax,0
	;mov edx,0
	;mov al,a
	;mov ah,b
	;add al,ah
	;mov dl,al
	;mov al,a
	;sub al,ah
	;sub dl,al
	;add dl,e
	;add dl,e

	;call dumpregs

;main endp
;end main

;--------------------------------------- QUESTION 6 ---------------------------------------  
;.data
;a byte 00010000b
;b byte 00010101b
;d byte 00110000b
;e byte 00100000b
;.code
;main proc
	
	;mov eax,0
	;mov edx,0
	;mov al,a
	;mov ah,b
	;add al,ah
	;mov dl,al
	;mov al,a
	;sub al,ah
	;sub dl,al
	;add dl,e
	;add dl,e

	;call dumpregs

;main endp
;end main

;--------------------------------------- QUESTION 7 ---------------------------------------  
.data
imm8 = 20
data1 word 8
data2 word 15
data3 word 20
.code
main proc
	
	mov eax,imm8
	mov bx,data1
	mov ecx,0
	add eax,ebx
	mov bx,data3
	sub eax,ebx
	mov ecx,imm8
	mov bx,data2
	add ecx,ebx
	add eax,ecx
	
	call dumpregs

main endp
end main
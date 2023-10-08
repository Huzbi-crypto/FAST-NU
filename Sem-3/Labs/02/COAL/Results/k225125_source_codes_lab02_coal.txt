;AUTHOR: Huzefa Saifuddin (Huzbi) - 22K-5125
;TITLE: COAL Lab02

include irvine32.inc

; ---------------------------------------- QUESTION 1 ----------------------------------------  
; Q1a
;.code
;main proc
	;mov eax,47d
	;add eax,039h
	;add eax,60d
	;add eax,85d
	;add eax,64d
	;add eax,54o
	;add eax,0ah

	;call writeint
	;call dumpregs
;main endp
;end main


; Q1b
;.code
;main proc
	;mov eax,30d
	;add eax,-9d
	;add eax,186d
	;add eax,-150d

	;call writeint
	;call dumpregs
;main endp
;end main

; Q1c
;.code
;main proc
	;mov eax,101110b
	;add eax,050Ah
	;add eax,6710d
	;add eax,1010001b
	;add eax,0fh

	;call writeint
	;call dumpregs
;main endp
;end main

; Q1d
;.code
;main proc
	;mov eax,10001101b
	;add eax,-0d83h
	;add eax,385d
	;add eax,10d
	;add eax,1111101b
	;add eax,-0e
	;add eax,0f

	;call writeint
	;call dumpregs
;main endp
;end main

; Q1e
.code
main proc
	mov eax,101b
	add eax,-9d
	add eax,01ah
	add eax,-56o

	call writeint
	call dumpregs
main endp
end main

; ---------------------------------------- QUESTION 2 ---------------------------------------- 
; Q2a
;.code
;main proc
	;mov edx,1d
	;mov eax,-10d
	;mov ebx,5d
	;mov ecx,-20d

	;add edx,eax
	;add edx,ebx
	;add edx,ecx
	;add edx,0ah
	;add edx,-65o
	;add edx,73d

	;mov eax,edx ;move the value stored in edx to eax to output the result

	;call writeint
	;call dumpregs
;main endp
;end main

; Q2b
;.code
;main proc
	;mov eax,150d
	;mov ebx,-10d

	;add eax,5adh
	;add eax,ebx
	;add eax,65o
	;add eax,65d
	;add eax,-11110111b

	;call writeint
	;call dumpregs
;main endp
;end main

; Q2c
;.code
;main proc
	;mov ebx,65d
	;mov eax,-10d

	;add ebx,5adh
	;add ebx,eax
	;add ebx,73o
	;add ebx,-11100101
	;add ebx,7bh

	;mov eax,ebx ;move the value stored in edx to eax to output the result

	;call writeint
	;call dumpregs
;main endp
;end main

; Q2d
;.code
;main proc
	;mov ecx,1d
	;mov ebx,10d

	;add ecx,110010101101b
	;add ecx,45h
	;add ecx,-73o
	;add ecx,ebx
	;add ecx,-ecx

	;mov eax,ecx ;move the value stored in edx to eax to output the result

	;call writeint
	;call dumpregs
;main endp
;end main
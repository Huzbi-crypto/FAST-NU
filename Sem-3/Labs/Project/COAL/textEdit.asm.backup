; Project: Typing Game
; Description:
; the n strings within the range of 2 to m size will fall and you have to clear all of them before they hit the bottom of the screen
; there are many levels and each level will gets faster and more strings
COMMENT!
Team Members:
	Huzefa Saifuddin - 22K-5125
	Suhaib Qazi - 22K-5073
	Areeb-ur-Rehman - 22K-6003
!
COMMENT!
features : You can change the number of strings and the size of the strings and speed before the start of the program
		 : It has levels and each level will increase the speed
		 : You do not need to start with the lowest string. You can start with any string at any where you want 
		 : but one exception is that if there is two strings starting with the same characters it will go to the string that is about to reach to the end
		 : If you made typo, it will show red color on the string that you are typing and it will restrict you to go to another character
		 : After beating 1 level, you can see your mistakes and accuracy
!

INCLUDE Irvine32.inc 

ExitProcess PROTO, dwExitCode: DWORD

.data
; *********** IMPORTANT VARIABLES ***********
speed DWORD 1500 ; milliseconds per string
_str = 6 ; number of strings
_str_size = 8 + 1 ; max size of the strings including the null +1
x = _str * _str_size ; for buffer array
y = _str * 2 ; for row and col storage array
z = _str ; for flag array

; *********** TEMPS *************
f_temp BYTE 1; f_temp = TRUE

.code
; ************************* RANDOMIZE ********************************
; low = lower bound of the random range
; high = higher bound of the random range
; returns in eax
BetterRandomRange PROC l: SDWORD, h: SDWORD
	mov eax, h
	mov ebx, l
	sub eax, ebx
	call RandomRange
	add eax, ebx
	ret
BetterRandomRange ENDP

; esi = address of the starting position of buffer
; n = random number from 2 to max size of the string
RandomString PROC uses esi ecx n: DWORD
	mov ecx, n
	L1:
		Invoke BetterRandomRange, 0, 26
		add eax, 'a'
		mov BYTE PTR [esi], al
		inc esi
	loop L1
	ret
RandomString ENDP

; ************************* CONTROLS ********************************
; this will set the speed according to the level
set_speed PROC
	mov ecx, level
	L7:
		.IF speed >= 600
			sub speed, 200
		.ENDIF
	loop L7
	ret
set_speed ENDP

; initialize all the strings with randomstrings
init_string PROC
	.data
		buffer BYTE x DUP (0) ; stores the strings
	.code
		mov esi, OFFSET buffer
		mov ecx, _str
		L2:
			Invoke BetterRandomRange, 2, _str_size - 1
			Invoke RandomString, eax
			add esi, _str_size ; move the esi to the next string
		loop L2
	ret
init_string ENDP

clear_twoD PROC
	mov esi, OFFSET twoD
	mov ecx, y
	
	L13:
		mov BYTE PTR [esi], -1
		inc esi
	loop L13
	mov count, 0
	ret
clear_twoD ENDP

clear_flag PROC
	mov esi, OFFSET flag_arr
	mov ecx, z

	L14:
		mov BYTE PTR [esi], 1
		inc esi
	loop L14
	ret
clear_flag ENDP

; this will update all the rows of the string by 1
update_row PROC uses esi
	mov ecx, count
	mov edi, OFFSET flag_arr
	L3:
		mov al, BYTE PTR [edi]
		.IF al == 1 ; check if the string is still active
			add BYTE PTR [esi], 1 ; if active increase the row
		.ENDIF
		.IF BYTE PTR [esi] == block
			mov game_over, 1
		.ENDIF
		add esi, 2
		inc edi
	loop L3
	ret
update_row ENDP

; this will keep track of count
update_col PROC uses esi
	add count, 1 ; increment the count

	mov eax, count
	mov cl, 2
	mul cl
	dec eax
	add esi, eax ; this will get to the index of column

	Invoke BetterRandomRange, 0, 120 - _str_size
	mov BYTE PTR [esi], al
	ret
update_col ENDP

; this will search the position of the first character input
search PROC uses ecx eax
	mov esi, OFFSET buffer
	mov ecx, 0
	L8:
		cmp ecx, count
		jz _L8

		.IF BYTE PTR [esi] == al
			mov gap, ecx
			jmp _L8
		.ENDIF

		inc ecx
		add esi, _str_size
		jmp L8
	_L8:
	ret
search ENDP

; this will save the input of the user
save_input PROC uses ecx
	.IF gap == -1
		jmp NOT_FOUND
	.ENDIF
	mov esi, OFFSET buffer

	push eax
	mov eax, gap
	mov ebx, _str_size
	mul ebx
	add esi, eax ; esi is now pointing to the gapped string
	pop eax ; restore the input

	mov ecx, input_ptr
	add esi, ecx ; esi is now pointing to the specific character
	mov bl, BYTE PTR [esi]

	.IF bl == al ; if the input character is the same as the gapped character
		mov BYTE PTR [input + ecx], al ; now save the input
		add input_ptr, 1
		mov mistake, 0
		add total_count, 1 ; add the word count
	.ELSE
		mov mistake, 1 ; this is flag
		add mistake_count, 1 ; this is count
		add total_count, 1 ; add the word count
	.ENDIF

	NOT_FOUND:
	ret
save_input ENDP

; this will clear the input string
clear_input PROC
	mov esi, OFFSET input
	mov ecx, input_ptr

	L9:
		mov BYTE PTR [esi], 0 ; clear all the inputs
		inc esi
	loop L9

	mov input_ptr, 0 ; reset the input_ptr
	mov gap, -1 ; reset the gap
	ret
clear_input ENDP

; this will clear the string that is the same as input in the buffer
update_flag PROC uses ecx
	.IF gap == -1 || input_ptr < 2
		jmp nothing
	.ENDIF
	mov esi, OFFSET buffer
	mov eax, gap
	mov ebx, _str_size
	mul ebx

	add esi, eax ; esi is now pointing to the gapped string in the buffer
	mov edi, OFFSET input ; edi is now pointing to the input

	mov ecx, 0
	L10:
		cmp ecx, _str_size ; size of the input
		jz _L10
		
		mov al, BYTE PTR [esi + ecx]
		mov bl, BYTE PTR [edi + ecx]
		.IF al != bl
			mov f_temp, 0; f_temp = FALSE
			jmp _L10
		.ENDIF

		inc ecx
		jmp L10
	_L10:
	
	.IF f_temp == 1 ; TRUE, IF you have deactived a string
		mov eax, gap
		mov BYTE PTR [flag_arr + eax], 0 ; this is to declare that the string at that position is deactivated

		mov ebx, _str_size
		mul ebx
		mov BYTE PTR [buffer + eax], 0

		call clear_input ; and clear the input
		call check_win ; check if you have win a level
	.ENDIF
	mov f_temp, 1 ; reset the flag
	nothing:
	ret
update_flag ENDP

; this is check all the flags of the strings to see if you have clear everything
check_win PROC
	mov esi, OFFSET flag_arr
	mov ecx, 0

	L11:
		cmp ecx, z
		jz _L11

		mov al, BYTE PTR [esi + ecx]
		.IF al == 1 ; there are still strings that are active
			mov f_temp, 0; f_temp = FALSE
			jmp _L11
		.ENDIF
		inc ecx
		jmp L11
	_L11:

	.IF f_temp == 1
		mov win, 1
	.ENDIF
	mov f_temp, 1 ; reset the flag
	ret
check_win ENDP

; ************************* PRINTS *************************
; this will print the input
print_input PROC uses ecx
	.IF gap == -1
		jmp no_input
	.ENDIF

	mov esi, OFFSET twoD ; to get the position
	mov eax, gap
	mov ebx, 2
	mul ebx
	add esi, eax ; this will point to the position of the gapped string

	mov dh, BYTE PTR [esi] ; row
	inc esi
	mov dl, BYTE PTR [esi] ; col
	call Gotoxy

	mov edx, OFFSET input
	.IF mistake == 0
		mov eax, lightCyan + (black * 16)
	.ELSEIF mistake == 1
		mov eax, lightRed + (black * 16)
	.ENDIF
	call SetTextColor
	call WriteString

	mov eax, white + (black * 16) ; change it back to white
	call SetTextColor
	no_input:
	ret
print_input ENDP

; this print_string will print one string each
print_string PROC uses eax ecx
	call clrscr
	call print_block
	mov esi, OFFSET twoD
	mov edx, OFFSET buffer
	.IF count == _str
		call update_row
	.ELSEIF count < _str
		call update_col
		call update_row
	.ENDIF
	.IF game_over == 1
		jmp skip
	.ENDIF
	mov ecx, count
	L6:
		push edx
		mov dh, BYTE PTR [esi] ; row
		inc esi
		mov dl, BYTE PTR [esi] ; col
		inc esi
		
		call Gotoxy
		pop edx
		call WriteString

		add edx, _str_size
	loop L6
	skip:
	ret
print_string ENDP

; print the mistakes and wpm
print_stats PROC
	.data
		text3 BYTE "-------------", 0
		text4 BYTE "STATS", 0
		text5 BYTE "MISTAKES: ", 0
		text6 BYTE "ACCURACY: ", 0
	.code
		mov eax, brown + (black * 16)
		call SetTextColor

		mov dh, 3
		mov dl, 4
		call Gotoxy
		mov edx, OFFSET text4
		call WriteString

		mov dh, 4
		mov dl, 0
		call Gotoxy
		mov edx, OFFSET text3
		call WriteString

		mov dh, 5
		mov dl, 1
		call Gotoxy
		mov edx, OFFSET text5
		call WriteString

		mov eax, mistake_count
		call WriteDec

		mov dh, 6
		mov dl, 1
		call Gotoxy
		mov edx, OFFSET text6
		call WriteString

		mov eax, total_count
		sub eax, mistake_count ; total - mistake
		mov ebx, 100
		mul ebx

		mov edx, 0
		mov ebx, total_count
		div ebx ; (total - mistake) * 100 / total
		call WriteDec

		mov al, '%'
		call WriteChar

		mov mistake_count, 0 ; reset the mistake_count after display
		mov total_count, 0 ; reset the word count
		mov accuracy, 0 ; reset the accuracy
	ret
print_stats ENDP

print_level PROC
	.data
		text1 BYTE "LEVEL ",0
	.code
		call clrscr
		mov dh, 14
		mov dl, 57
		call Gotoxy

		mov eax, Green + (black * 16)
		call SetTextColor

		mov edx, OFFSET text1
		call WriteString
		mov eax, level
		call WriteDec

		.IF level > 1
			call print_stats ; print the mistakes and wpm
		.ENDIF

		mov eax, lightGray + (black * 16) 
		call SetTextColor

		mov dh, 16
		mov dl, 47
		call Gotoxy
		call WaitMsg

		mov eax, white + (black * 16) ; change it back to white
		call SetTextColor
	ret
print_level ENDP

print_block PROC
	.data
		str_block1 BYTE 120 DUP ('*'), 0
		str_block2 BYTE 120 DUP ('^'),0
		block = 28
	.code
		mov eax, red + (black * 16) ; text color
		call SetTextColor

		mov dh, block + 1 ; row
		mov dl, 0 ; col
		call Gotoxy
		mov edx, OFFSET str_block1
		call WriteString

		mov dh, block + 2 ; row
		mov dl, 0 ; col
		call Gotoxy
		mov edx, OFFSET str_block2
		call WriteString

		mov eax, white + (black * 16) ; text color
		call SetTextColor
	ret
print_block ENDP

print_over PROC
	.data
		text2 BYTE "GAME OVER!!", 0
	.code
		mov dh, 15; row
		mov dl, 55; col
		call Gotoxy

		mov eax, red + (black * 16) 
		call SetTextColor

		mov edx, OFFSET text2
		call WriteString

		mov eax, white + (black * 16) ; change it back to white
		call SetTextColor
	ret
print_over ENDP

; ************************* USERINTERFACE AND INPUT PARTS ***************************
user_input PROC
	.data
		   
		; *********** ROW/COL STORAGE ***********
		twoD BYTE y DUP (-1) ; stores row/col for each string
		count DWORD 0 ; this will count the number of strings printed
		; max row = 30
		; max col = 120
		; *********** FLAGS ***********
		flag_arr BYTE z DUP (1) ; this flag array is for the cleared buffers
		mistake BYTE 0 ; for the red display
		game_over BYTE 0 ; boolean flag
		win BYTE 0
		; *********** INPUT STORAGE ***********
		input BYTE _str_size DUP (0) ; including the null
		input_ptr DWORD 0 ; this is to keep track of the input
		; ************* STATS *************
		total_count DWORD 0 ; to keep track of total input
		mistake_count DWORD 0 ; to keep track of the number of mistakes
		accuracy DWORD 0 ; this will to calculate accuracy percent
		; *********** FOR THIS FUNCTION ***********
		gap DWORD -1 ; this will save the nth of the string
		timer DWORD ?
	.code
		call print_block ; print the block first

		mov ecx, speed
		call GetMseconds
		mov timer, eax
		add timer, ecx
		L4:
			call GetMseconds
			.IF eax >= timer
				call print_string
				mov timer, eax
				add timer, ecx
			.ENDIF

			.IF game_over == 1
				call clrscr
				call print_over
				jmp done
			.ENDIF

			call print_input
			call update_flag

			.IF win == 1
				mov win, 0
				call clear_twoD
				call clear_flag
				jmp done
			.ENDIF

			mov eax, 50
			call Delay
			call ReadKey
			jz L4

			.IF gap == -1
				call search
			.ENDIF
			call save_input
			jmp L4
		done:
	ret
user_input ENDP
 
; *************************************** MAIN ***************************************
; this function will do all the necessities
typing_game PROC
	.data
		level DWORD 0
	.code
		call Randomize ; reseed the random number generator
		L5:
			.IF game_over == 1
				nop
			.ELSE
				add level, 1
				call print_level
				call set_speed
				call init_string
				call clrscr ; clears the screen
				call user_input
			.ENDIF
		jmp L5
	ret
typing_game ENDP

main PROC
	call typing_game
    INVOKE ExitProcess, 0
main ENDP
END main

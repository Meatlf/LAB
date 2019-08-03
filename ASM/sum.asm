; sum.asm - saving the results of addition in varibale named sum.
; Chapter 3 example

.386
.model flat,stdcall
.stack 4096
ExitProcess proto,dwExitCode:dword

.data						; this is the data area
sum DWORD 0					; create a variable named sum

.code
main proc
	mov	eax,5				; move 5 to the eax register	
	add	eax,6				; add 6 to the eax register	
	mov sum,eax 

	invoke ExitProcess,0	; end the program
main endp
end main
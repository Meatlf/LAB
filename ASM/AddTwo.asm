; AddTwo.asm - adds two 32-bit integers.
; Chapter 3 example

.386
.model flat,stdcall
.stack 4096
ExitProcess proto,dwExitCode:dword

.code
main proc
	mov	eax,5				; move 5 to the eax register	
	add	eax,6				; add 6 to the eax register	

	invoke ExitProcess,0	; end the program
main endp
end main
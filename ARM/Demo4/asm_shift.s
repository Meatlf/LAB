/*
 * asm_shift.s
 *
 *  Created on: 20190422
 *      Author: tztang
 */

.text

.global asm_shift

asm_shift:
	MOV W0,#0x11
	LSL W1,W0,#1
	LSL W2,W1,#1
	RET

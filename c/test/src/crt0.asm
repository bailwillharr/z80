;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; crt0.asm - Bailey Harrison ;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

	.module crt0
	.globl	_main

	.area	_HEADER (ABS)
	;; Reset vector
	.org 	#0x8000

	;; Set stack pointer directly above top of memory.
	ld	sp,#0x0000

	;; Initialise global variables
	call	gsinit
	call	_main
	jp	_exit

	;; Ordering of segments for the linker.
	.area	_HOME
	.area	_CODE
	.area	_INITIALIZER
	.area   _GSINIT
	.area   _GSFINAL

	.area	_DATA
	.area	_INITIALIZED
	.area	_BSEG
	.area   _BSS
	.area   _HEAP

	.area   _CODE

_exit::
1$:
	halt
	jr	1$

	.area   _GSINIT
gsinit::
	; initialise global variables
	ld	bc, #l__INITIALIZER
	ld	a, b
	or	a, c
	jr	Z, gsinit_next
	ld	de, #s__INITIALIZED
	ld	hl, #s__INITIALIZER
	ldir
gsinit_next:

	.area   _GSFINAL
	ret


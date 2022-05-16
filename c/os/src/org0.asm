		SECTION	HOME

		INCLUDE	"computer.inc"
		
		ORG		0
		ld		a, $E0
		out		(IO_MMU_B0), a
		jp		start

        defs    $0008-ASMPC
if (ASMPC<>$0008)
        defs    CODE_ALIGNMENT_ERROR
endif
rst08:
        defs    $0010-ASMPC
if (ASMPC<>$0010)
        defs    CODE_ALIGNMENT_ERROR
endif
rst10:
        defs    $0018-ASMPC
if (ASMPC<>$0018)
        defs    CODE_ALIGNMENT_ERROR
endif
rst18:
        defs    $0020-ASMPC
if (ASMPC<>$0020)
        defs    CODE_ALIGNMENT_ERROR
endif
rst20:
        defs    $0028-ASMPC
if (ASMPC<>$0028)
        defs    CODE_ALIGNMENT_ERROR
endif
rst28:
        defs    $0030-ASMPC
if (ASMPC<>$0030)
        defs    CODE_ALIGNMENT_ERROR
endif
rst30:

; INT
		defs    $0038-asmpc
if (asmpc<>$0038)
        defs    code_alignment_error
endif
rst38:
		ei
		ret

		; NMI
		defs    $0066-asmpc
if (asmpc<>$0066)
        defs    code_alignment_error
endif
nmi:
		retn

start:
		inc		a				; a = $E1
		out		(IO_MMU_B1), a
		inc		a				; a = $E2
		out		(IO_MMU_B2), a
		inc		a				; a = $E3
		out		(IO_MMU_B3), a
		ld		sp, 0

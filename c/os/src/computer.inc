; computer.inc
; Bailey Harrison
; Definitions of the computer components without any expansion cards
	DEFC	IO_MMU_B0	= 0x00
	DEFC	IO_MMU_B1	= 0x01
	DEFC	IO_MMU_B2	= 0x02
	DEFC	IO_MMU_B3	= 0x03
	DEFC	IO_MMU_EN	= 0x07
	; $01 = 2.5 MHz, $02 = 20MHz, $03 = toggle
	DEFC	IO_CLK		= 0x10
	DEFC	IO_7SEG		= 0x20
	DEFC	IO_SLOT1	= 0x30
	DEFC	IO_SLOT2	= 0x40
	DEFC	IO_SLOT3	= 0x50
	DEFC	IO_SLOT4	= 0x60
	DEFC	IO_SLOT5	= 0x70
	DEFC	IO_SLOT6	= 0x80

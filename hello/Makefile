NAME		:= hello
ENTRY		:= main.z80

include ../z80.mk

test: $(NAME).rom
	stty -F /dev/ttyUSB0 9600
	sx -vv $(NAME).rom < /dev/ttyUSB0 > /dev/ttyUSB0
	-st -g 80x24 -i -l /dev/ttyUSB0 9600

.PHONY: test


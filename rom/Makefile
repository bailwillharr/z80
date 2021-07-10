NAME	:= rom
ENTRY	:= init.z80

include ../z80.mk

run: $(NAME).rom
	stty -F /dev/ttyUSB0 ispeed 115200
	sx -vv $(NAME).rom < /dev/ttyUSB0 > /dev/ttyUSB0
	-st -g 80x24 -i -l /dev/ttyUSB0 115200

.PHONY: run


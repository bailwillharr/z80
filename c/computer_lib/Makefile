all: lib/libcomputer.a

C_SRC := $(shell find src -name "*.c")
C_OBJ := $(C_SRC:.c=.rel)
ASM_SRC := $(shell find src -name "*.s")
ASM_OBJ := $(ASM_SRC:.s=.rel)

OBJ := $(C_OBJ) $(ASM_OBJ)

lib/libcomputer.a: $(OBJ)
	sdar rcs $@ $^

%.rel: %.c
	sdcc -mz80 -c -o $@ $^

%.rel: %.s
	sdasz80 -plosgff -o $@ $^

.PHONY: all

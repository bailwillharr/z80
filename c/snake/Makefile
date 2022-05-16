NAME	:=	test

CC	:= zcc
AS	:= zasm

CFLAGS	:= -mz80 --nostdinc
LDFLAGS := --code-loc 0x8000 --code-size 0x4000 --stack-loc 0x0000 --data-loc 0x0000 --no-std-crt0

C_SRC := $(shell find src -name "*.c")
C_OBJ := $(C_SRC:.c=.rel)
ASM_SRC := $(shell find src -name "*.s")
ASM_OBJ := $(ASM_SRC:.s=.rel)
OBJ := $(C_OBJ) $(ASM_OBJ)

all: $(NAME).bin

$(NAME).bin: $(NAME).ihx
	objcopy -I ihex -O binary $(NAME).ihx $(NAME).bin

$(NAME).ihx: $(OBJ)
	$(CC) -o $@ $(CFLAGS) $(LDFLAGS) $^

%.rel: %.c
	$(CC) -c -o $@ $(CFLAGS) $^

%.rel: %.s
	$(AS) -plosgff -o $@ $^

clean:
	rm -f $(NAME).bin $(NAME).ihx $(NAME).lk $(NAME).map $(NAME).noi
	rm -f $(OBJ)
	rm -f $(OBJ:.rel=.lst)
	rm -f $(OBJ:.rel=.sym)
	rm -f $(C_SRC:.c=.asm)

.PHONY: all clean

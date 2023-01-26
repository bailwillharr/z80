NAME	:=	test

CC	:= zcc 
CFLAGS	:= +embedded -compiler sdcc -mz80 --nostdlib --asm=z80asm
LDFLAGS := --code-loc 0x8000 --code-size 0x4000 --stack-loc 0x0000 --data-loc 0x0000 --asm=z80asm
#--no-std-crt0

C_SRC := $(shell find src -name "*.c")
C_OBJ := $(C_SRC:.c=.rel)
ASM_SRC := $(shell find src -name "*.s")
ASM_OBJ := $(ASM_SRC:.s=.rel)
OBJ := $(C_OBJ) $(ASM_OBJ)

all: $(NAME).bin

$(NAME).bin: $(NAME).ihx
	objcopy -I ihex -O binary $(NAME).ihx $(NAME).bin

$(NAME).ihx: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(LDFLAGS) $^

%.rel: %.c
	$(CC) $(CFLAGS) -c -o $@ $^

%.rel: %.s
	$(CC) $@ $^

clean:
	rm -f $(NAME).bin $(NAME).ihx $(NAME).lk $(NAME).map $(NAME).noi
	rm -f $(OBJ)
	rm -f $(OBJ:.rel=.lst)
	rm -f $(OBJ:.rel=.sym)
	rm -f $(C_SRC:.c=.asm)

.PHONY: all clean

FILES		?= $(wildcard *.z80)
BUILDCMD	?= zasm -uwy

$(NAME).rom: $(FILES)
	$(BUILDCMD) -l $(NAME).lst -o $(NAME).rom -i $(ENTRY)

clean:
	rm -f $(NAME).rom
	rm -f $(NAME).lst

.PHONY: clean

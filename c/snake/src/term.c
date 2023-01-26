#include "uart.h"
#include "conv.h"

#include "term.h"

void putc(char c)
{
	uart_write_byte(c);
}

void puts(const char *s)
{
	for (int i = 0; s[i] != '\0'; i++)
		putc(s[i]);
}

void clear()
{
	puts("\033[2J\033[1;1H");
}

void setcursor(char x, char y)
{
	char buffer[] = "\033[XXX;XXXH";
	uint8_to_dec(y, buffer + 2);
	uint8_to_dec(x, buffer + 6);
	puts(buffer);
}

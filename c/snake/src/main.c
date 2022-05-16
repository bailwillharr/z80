/*
 * main.c - Bailey Harrison
 */

#include "uart.h"
#include "term.h"
#include "conv.h"
#include "led.h"

const char *HELLO = "Hello world!\r\n";

static void primes()
{
	char buffer[] = "XXXXX\r\n";
	for (unsigned int i = 2; i < 50000; i++) {
		char isPrime = 1;
		for (unsigned int j = 2; j <= i / 2; j++) {
			if (i % j == 0) {
				isPrime = 0;
				break;
			}
		}
		if (isPrime) {
			uint16_to_dec(i, buffer);
			puts(buffer);
			led_write((((i / 10000) % 10) << 4) | ((i / 1000) % 10));
		}
	}
}

void main()
{
	clear();

	puts("please reconnect at 1,000,000 Bd\r\n");
	uart_set_baud(1);
	while (uart_read_byte() != '\r') ;

	for ( ;; ) {
		primes();
	}

}

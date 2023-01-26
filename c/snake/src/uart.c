#include "uart.h"

#define UART_PREFIX IO_SLOT6

// define IO ports
__sfr __at UART_PREFIX | 0x0 uart_rbr;
__sfr __at UART_PREFIX | 0x0 uart_thr;
__sfr __at UART_PREFIX | 0x1 uart_ier;
__sfr __at UART_PREFIX | 0x2 uart_iir;
__sfr __at UART_PREFIX | 0x2 uart_fcr;
__sfr __at UART_PREFIX | 0x3 uart_lcr;
__sfr __at UART_PREFIX | 0x4 uart_mcr;
__sfr __at UART_PREFIX | 0x5 uart_lsr;
__sfr __at UART_PREFIX | 0x6 uart_msr;
__sfr __at UART_PREFIX | 0x7 uart_scr;
__sfr __at UART_PREFIX | 0x7 uart_scr;

// DLAB == 1
__sfr __at UART_PREFIX | 0x0 uart_dll;
__sfr __at UART_PREFIX | 0x1 uart_dlm;

void uart_write_byte(char c)
{
	// wait until there is space in the Transmit Holding Register
	while ((uart_lsr & 0b01000000) == 0) ;
	uart_thr = c;
}

char uart_read_byte()
{
	// wait until a character is received
	while ((uart_lsr & 0b00000001) == 0) ;
	return uart_rbr;
}

void uart_set_baud(unsigned int divisor)
{
	uart_lcr = 0b10000011;		// 8N1, enable DLAB
	uart_dlm = divisor >> 8;
	uart_dll = divisor;
	uart_lcr = 0b00000011;		// 8N1, disable DLAB
}

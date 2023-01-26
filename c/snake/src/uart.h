#ifndef UART_H
#define UART_H

#include "computer.h"

// functions
void uart_write_byte(char c);
char uart_read_byte();
void uart_set_baud(unsigned int divisor);

#endif

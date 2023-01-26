#include "conv.h"

static char half_byte_to_hex(char n)
{
	const char HEX_TABLE[16] = {
		'0', '1', '2', '3',
		'4', '5', '6', '7',
		'8', '9', 'A', 'B',
		'C', 'D', 'E', 'F'
	};
	return HEX_TABLE[n];
}



/**********************
** integer to string **
**********************/

// none of these functions add the null terminator

// -> HEX STR

// 's' must hold at least 2 bytes
void uint8_to_hex(char n, char *s)
{
	s[0] = half_byte_to_hex(n >> 4);
	s[1] = half_byte_to_hex(n & 0x0F);
}

// 's' must hold at least 4 bytes
void uint16_to_hex(unsigned short n, char *s)
{
	uint8_to_hex(n >> 8, s);
	uint8_to_hex(n, s + 2);
}

// -> DECIMAL STR

// 's' must hold at least 3 bytes
void uint8_to_dec(char n, char *s)
{
	s[0] = ((n / 100) % 10) + 48;
	s[1] = ((n /  10) % 10) + 48;
	s[2] = ( n        % 10) + 48;
}

// 's' must hold at least 5 bytes
void uint16_to_dec(unsigned short n, char *s)
{
	s[0] = ((n / 10000) % 10) + 48;
	s[1] = ((n /  1000) % 10) + 48;
	s[2] = ((n /   100) % 10) + 48;
	s[3] = ((n /    10) % 10) + 48;
	s[4] = ( n          % 10) + 48;
}

#include "led.h"

__sfr __at 0x20 led_port;

void led_write(char n)
{
	led_port = n;
}

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "terminal.h"
#include "string.h"

/* Check if proper compiler is used */
#if defined(__linux__)
#error "You are not using a cross-compiler, you will most certainly run into trouble"
#endif

#if !defined(__i386__)
#error "CosmOS needs to be compiled with a ix86-elf compiler"
#endif
/*									*/

void kernel_main(void)
{
	terminal_initialize();
	for (int b = 0; b < 2600; b++)
	{
		for (uint8_t a = 0; a < 26; a++)
		{
			terminal_setcolor(a % 16, VGA_COLOR_BLACK);
			terminal_putc(0x41 + a);
		}
	}

	terminal_setcolor(VGA_COLOR_LIGHT_GREY, VGA_COLOR_BLACK);
	terminal_puts("\nHello, kernel World!! :)");
	char str[1000];
	memset(str, 0, 1000);
	terminal_putc('\n');terminal_puts(itoa(123, str, 10));
	terminal_putc('\n');terminal_puts(ultoa(0xdeadbeef, str, 16));
	terminal_putc('\n');terminal_puts(itoa(0b1010, str, 2));
	}

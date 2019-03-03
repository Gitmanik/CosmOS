#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "drivers/terminal/terminal.h"

/* Check if proper compiler is used */
#if defined(__linux__)
#error "You are not using a cross-compiler, you will most certainly run into trouble"
#endif

#if !defined(__i386__)
#error "CosmOS needs to be compiled with a ix86-elf compiler"
#endif
/*																												*/

void kernel_main(void)
{
	terminal_initialize();
	for (uint8_t a = 0; a < 26; a++)
	{
		terminal_setcolor(a % 16, BLACK);
		terminal_putchar(0x41 + a);
	}
	terminal_setcolor(LIGHT_GREY, BLACK);
	terminal_writestring("\nHello, kernel World!! :)");
}

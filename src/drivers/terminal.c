#include <stdint.h>
#include <stddef.h>

#include "terminal.h"
#include "string.h"
#include "io.h"

size_t terminal_row;
size_t terminal_column;
uint8_t terminal_color;
uint16_t* terminal_buffer = (uint16_t*) 0xB8000;

static inline uint16_t vga_entry(unsigned char uc, uint8_t color)
{
	return (uint16_t) uc | (uint16_t) color << 8;
}

void terminal_putentryat(char c, uint8_t color, size_t x, size_t y)
{
	const size_t index = y * VGA_WIDTH + x;
	terminal_buffer[index] = vga_entry(c, color);
}

void terminal_updatecursor()
{
	uint16_t pos = terminal_row * VGA_WIDTH + terminal_column;
	outb(0x3D4, 0x0F);
	outb(0x3D5, (uint8_t) (pos & 0xFF));
	outb(0x3D4, 0x0E);
	outb(0x3D5, (uint8_t) ((pos >> 8) & 0xFF));
}

void terminal_setcursor(size_t new_column, size_t new_row)
{
	terminal_row = new_row;
	terminal_column = new_column;
	terminal_updatecursor();
}

void terminal_scroll()
{
	for (size_t row = 0; row < VGA_HEIGHT; row++)
		memcpy((void*) terminal_buffer + VGA_WIDTH * 2 * row, (void*) terminal_buffer + VGA_WIDTH * 2 * (row + 1), VGA_WIDTH * 2);

	for (size_t i = 0; i < VGA_WIDTH; i++)
		terminal_putentryat(' ', terminal_color, i, VGA_HEIGHT);
}

void terminal_setcolor(enum vga_color fg, enum vga_color bg)
{
	terminal_color =  fg | bg << 4;
}

void terminal_fill(enum vga_color fg, enum vga_color bg)
{
	terminal_setcolor(fg, bg);

	for (size_t i = 0; i < VGA_HEIGHT * VGA_WIDTH; i++)
		terminal_putc(' ');

	terminal_setcursor(0,0);
}

void terminal_clear()
{
	terminal_fill(VGA_COLOR_LIGHT_GREY, VGA_COLOR_BLACK);
}

void terminal_initialize(void)
{
	terminal_clear();
	terminal_setcolor(VGA_COLOR_LIGHT_GREY, VGA_COLOR_BLACK);
}

void terminal_newline(void)
{
	terminal_setcursor(0,++terminal_row);
	if (terminal_row == VGA_HEIGHT)
	{
		terminal_scroll();
		terminal_setcursor(0,VGA_HEIGHT - 1);
	}
}

void terminal_putc(char c)
{
	if (c == '\n')
	{
		terminal_newline();
	} else
	{
		terminal_putentryat(c, terminal_color, terminal_column, terminal_row);
		if (++terminal_column == VGA_WIDTH)
		{
			terminal_newline();
		}
	}
	terminal_updatecursor();
}

void terminal_puts(const char* data)
{
	for (size_t i = 0; i < strlen(data); i++)
		terminal_putc(data[i]);
}
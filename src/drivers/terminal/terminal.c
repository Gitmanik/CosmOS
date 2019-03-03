/**
 * @Author: Paweł Reich <Gitmanik>
 * @Date:   2019-03-03T13:12:10+01:00
 * @Email:  thegitman@outlook.com
 * @Project: CosmOS
 * @Filename: terminal.c
 * @Last modified by:   Gitmanik
 * @Last modified time: 2019-03-03T13:42:51+01:00
 */

#include "terminal.h"
#include <stdint.h>
#include <stddef.h>
#include "../../misc/string.h"

size_t terminal_row;
size_t terminal_column;
uint8_t terminal_color;
uint16_t* terminal_buffer = (uint16_t*) 0xB8000;

void terminal_setcolor(enum vga_color fg, enum vga_color bg)
{
	terminal_color =  fg | bg << 4;
}

static inline uint16_t vga_entry(unsigned char uc, uint8_t color)
{
	return (uint16_t) uc | (uint16_t) color << 8;
}

void terminal_clear(void)
{
  memset(terminal_buffer, 0, VGA_WIDTH * VGA_HEIGHT * 2);
}

void terminal_initialize(void)
{
	terminal_row = 0;
	terminal_column = 0;
	terminal_setcolor(LIGHT_GREY, BLACK);
  terminal_clear();
}

void terminal_putentryat(char c, uint8_t color, size_t x, size_t y)
{
	const size_t index = y * VGA_WIDTH + x;
	terminal_buffer[index] = vga_entry(c, color);
}

void terminal_newline(void)
{
	terminal_column = 0;
	if (++terminal_row == VGA_HEIGHT)
	{
		terminal_row = 0;
	}
}

void terminal_putchar(char c)
{
	if (c == '\n')
	{
		terminal_newline();
		return;
	}
	terminal_putentryat(c, terminal_color, terminal_column, terminal_row);
	if (++terminal_column == VGA_WIDTH)
	{
		terminal_newline();
	}
}

void terminal_write(const char* data, size_t size)
{
	for (size_t i = 0; i < size; i++)
		terminal_putchar(data[i]);
}

void terminal_writestring(const char* data)
{
	terminal_write(data, strlen(data));
}

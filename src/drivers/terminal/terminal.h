#pragma once

#include <stdint.h>
#include <stddef.h>

void vga_clear();

static const size_t VGA_WIDTH = 80;
static const size_t VGA_HEIGHT = 25;

enum vga_color {
	BLACK = 0,
	BLUE = 1,
	GREEN = 2,
	CYAN = 3,
	RED = 4,
	MAGENTA = 5,
	BROWN = 6,
	LIGHT_GREY = 7,
	DARK_GREY = 8,
	LIGHT_BLUE = 9,
	LIGHT_GREEN = 10,
	LIGHT_CYAN = 11,
	LIGHT_RED = 12,
	LIGHT_MAGENTA = 13,
	LIGHT_BROWN = 14,
	WHITE = 15,
};

void terminal_initialize(void);
void terminal_setcolor(enum vga_color fg, enum vga_color bg);
void terminal_clear();
void terminal_putchar(char c);
void terminal_writestring(const char* data);

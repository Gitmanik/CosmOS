/**
 * @Author: Paweł Reich <Gitmanik>
 * @Date:   2019-03-03T13:17:25+01:00
 * @Email:  thegitman@outlook.com
 * @Project: CosmOS
 * @Filename: terminal.h
 * @Last modified by:   Gitmanik
 * @Last modified time: 2019-03-03T12:56:56+01:00
 */

#pragma once

#include <stdint.h>
#include <stddef.h>

void vga_clear();

static const size_t VGA_WIDTH = 80;
static const size_t VGA_HEIGHT = 25;

void terminal_initialize(void);
void terminal_setcolor(uint8_t color);
void terminal_putchar(char c);
void terminal_writestring(const char* data);

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

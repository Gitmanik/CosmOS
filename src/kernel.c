/**
 * @Author: Paweł Reich <Gitmanik>
 * @Date:   2019-03-03T13:14:46+01:00
 * @Email:  thegitman@outlook.com
 * @Project: CosmOS
 * @Filename: kernel.c
 * @Last modified by:   Gitmanik
 * @Last modified time: 2019-03-03T12:58:12+01:00
 */

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "drivers/terminal/terminal.h"

/* Check if proper compiler is used */
#if defined(__linux__)
#error "You are not using a cross-compiler, you will most certainly run into trouble"
#endif

#if !defined(__i386__)
#error "This tutorial needs to be compiled with a ix86-elf compiler"
#endif
/*																												*/

void kernel_main(void)
{
	/* Initialize terminal interface */
	terminal_initialize();

	/* Newline support is left as an exercise. */
	terminal_writestring("Hello, kernel World!\nAAAA:)");
}

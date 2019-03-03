/**
 * @Author: Paweł Reich <Gitmanik>
 * @Date:   2019-03-03T16:37:58+01:00
 * @Email:  thegitman@outlook.com
 * @Project: CosmOS
 * @Filename: inlineassembly.c
 * @Last modified by:   Gitmanik
 * @Last modified time: 2019-03-03T17:53:43+01:00
 */

#include <stdint.h>
#include "inlineassembly.h"

void outb(uint16_t port, uint8_t val)
{
    asm volatile ( "outb %0, %1" : : "a"(val), "Nd"(port) );
    /* There's an outb %al, $imm8  encoding, for compile-time constant port numbers that fit in 8b.  (N constraint).
     * Wider immediate constants would be truncated at assemble-time (e.g. "i" constraint).
     * The  outb  %al, %dx  encoding is the only option for all other cases.
     * %1 expands to %dx because  port  is a uint16_t.  %w1 could be used if we had the port number a wider C type */
}

uint8_t inb(uint16_t port)
{
    uint8_t ret;
    asm volatile ( "inb %1, %0"
                   : "=a"(ret)
                   : "Nd"(port) );
    return ret;
}

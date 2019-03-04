#include "isr.h"
#include "terminal.h"
#include "string.h"

char buf[100];

char* ints[] =
{
    "Divide by zero exception",
    "Debug exception",
    "Non maskable interrupt",
    "Breakpoint exception",
    "Into detected overflow",
    "Out of bounds exception",
    "Invalid opcode exception",
    "No coprocessor exception",
    "Double fault",
    "Coprocessor segment overrun",
    "Bad TSS",
    "Segment not present",
    "Stack fault",
    "General protection fault ",
    "Page fault",
    "Unknown interrupt exception",
    "Coprocessor fault",
    "Alignment check exception",
    "Machine check exception",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved"
};

void isr_handler(registers_t regs)
{
    terminal_fill(VGA_COLOR_RED, VGA_COLOR_BLACK);
    char* message = "RECEIVED INTERRUPT:";
    terminal_setcursor((VGA_WIDTH - strlen(message)) / 2, VGA_HEIGHT / 2 - 1);
    terminal_puts(message);

    char buf[100];

    terminal_setcursor((VGA_WIDTH - strlen(ints[regs.int_no]) - strlen(itoa(regs.int_no, buf, 10)) - 3) / 2, VGA_HEIGHT / 2);
    terminal_puts(ints[regs.int_no]);
    terminal_puts(" (");terminal_puts(buf);terminal_puts(")");
    memset((void*) buf, 0, strlen(buf));

    message = "System halted.";
    terminal_setcursor((VGA_WIDTH - strlen(message)) / 2, VGA_HEIGHT / 2 + 1);
    terminal_puts(message);

    for(;;);
}
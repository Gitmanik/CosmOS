# @Author: Paweł Reich <Gitmanik>
# @Date:   2019-03-03T12:09:14+01:00
# @Email:  thegitman@outlook.com
# @Project: CosmOS
# @Filename: makefile
# @Last modified by:   Gitmanik
# @Last modified time: 2019-03-03T13:01:56+01:00

C_SOURCES = $(shell find . -name "*.c")
C_HEADERS = $(shell find . -name "*.h")
C_OBJECTS = ${C_SOURCES:.c=.o}

ASM_SOURCES = $(shell find . -name "*.asm")
ASM_OBJECTS = ${ASM_SOURCES:.asm=.o}

ISO_NAME = CosmOS.iso

all:${ISO_NAME}

clean:
	rm -rf **/*.o **/*.elf **/*.bin **/*.iso

run: ${ISO_NAME}
	qemu-system-x86_64 -boot d -cdrom $< -m 32

# Build OS image
CosmOS.iso: isodir/boot/CosmOS.bin
	grub-mkrescue -o ${ISO_NAME} isodir

isodir/boot/CosmOS.bin: ${ASM_OBJECTS} ${C_OBJECTS}
	i686-elf-gcc -T src/linker.ld -o isodir/boot/CosmOS.bin -ffreestanding -O2 -nostdlib $^

%.o: %.asm
	nasm -felf32 "$<" -o "$@"

%.o: %.c
	i686-elf-gcc -ffreestanding -m32 -Wall -Wextra -c $< -o $@

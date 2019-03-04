C_SOURCES = $(shell find . -name "*.c")
C_HEADERS = $(shell find . -name "*.h")
C_OBJECTS = ${C_SOURCES:.c=.o}

ASM_SOURCES = $(shell find . -name "*.asm")
ASM_OBJECTS = ${ASM_SOURCES:.asm=.o}

GCC = ~/opt/cross/bin/i686-elf-gcc
LINKER = src/linker.ld

ISO_NAME = CosmOS.iso

default: run

all:${ISO_NAME}

clean:
	find . -name \*.o -type f -delete
	find . -name \*.bin -type f -delete
	find . -name \*.iso -type f -delete

run: ${ISO_NAME}
	qemu-system-x86_64 -boot d -cdrom $< -m 32

# Build OS image
CosmOS.iso: isodir/boot/CosmOS.bin
	grub-mkrescue -o ${ISO_NAME} isodir

isodir/boot/CosmOS.bin: ${ASM_OBJECTS} ${C_OBJECTS}
	${GCC} -T ${LINKER} -o isodir/boot/CosmOS.bin -ffreestanding -O2 -nostdlib $^

%.o: %.asm
	nasm -felf32 "$<" -o "$@"

%.o: %.c
	${GCC} -ffreestanding -m32 -Wall -Wextra -Isrc/include -c $< -o $@

C_SOURCES = $(shell find . -name "*.c")
C_HEADERS = $(shell find . -name "*.h")
C_OBJECTS = ${C_SOURCES:.c=.o}

ASM_SOURCES = $(shell find . -name "*.asm")
ASM_OBJECTS = ${ASM_SOURCES:.asm=.o}

ISO_NAME = CosmOS.iso

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
	i686-elf-gcc -T src/linker.ld -o isodir/boot/CosmOS.bin -ffreestanding -O2 -nostdlib $^

%.o: %.asm
	nasm -felf32 "$<" -o "$@"

%.o: %.c
	i686-elf-gcc -ffreestanding -m32 -Wall -Wextra -c $< -o $@

OBJECTS = $(patsubst %.cpp,%.o, $(shell find src/ -name *.cpp)) src/start.o
CC = g++
CFLAGS = -m32 -nostdlib -nostdinc -fno-builtin -fno-stack-protector -nostartfiles -nodefaultlibs -Wall -O -fstrength-reduce -fomit-frame-pointer -finline-functions -I./src/include -c
LDFLAGS = -T link.ld -melf_i386
AS = nasm
ASFLAGS = -f elf

all: kernel

kernel: $(OBJECTS)
	# echo "$(OBJECTS)"
	ld $(LDFLAGS) $(OBJECTS) -o kernel

kerndev.iso: kernel
	mv kernel isofiles/boot/
	grub-mkrescue -o kerndev.iso isofiles

run: kerndev.iso
	qemu-system-i386 -cdrom kerndev.iso

debug: kernel
	objcopy --only-keep-debug kernel kernel.debug
	qemu-system-i386 -s -S -kernel kernel


%.o: %.cpp
	$(CC) $(CFLAGS) $< -o $@

%.o: %.asm
	$(AS) $(ASFLAGS) $< -o $@

clean:
	rm $(OBJECTS)
	rm kernel

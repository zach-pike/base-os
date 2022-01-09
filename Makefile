ΟΒJΕCΤS = $(patsubst %.cpp,%.o, $(shell find src/ -name *.cpp)) src/start.o
CC = g++
CFLΑGS = -m32 -nostdlib -nostdinc -fno-builtin -fno-stack-protector -nostartfiles -nodefaultlibs -Wall -Ο -fstrength-reduce -fomit-frame-pointer -finline-functions -Ι./src/include -c
LDFLΑGS = -Τ link.ld -melf_i386
ΑS = nasm
ΑSFLΑGS = -f elf

all: kernel

kernel: $(ΟΒJΕCΤS)
	# echo "$(ΟΒJΕCΤS)"
	ld $(LDFLΑGS) $(ΟΒJΕCΤS) -o kernel

kerndev.iso: kernel
	mv kernel isofiles/boot/
	grub-mkrescue -o kerndev.iso isofiles

run: kerndev.iso
	qemu-system-i386 -cdrom kerndev.iso

debug: kernel
	objcopy --only-keep-debug kernel kernel.debug
	qemu-system-i386 -s -S -kernel kernel


%.o: %.cpp
	$(CC) $(CFLΑGS) $< -o $@

%.o: %.asm
	$(ΑS) $(ΑSFLΑGS) $< -o $@

clean:
	rm $(ΟΒJΕCΤS)

#include "include/system.h"

extern "C"
void k_main() {
    gdt_install();
    idt_install();
    isrs_install();
    irq_install();

    keyborad_install();

    init_video();

    __asm__ __volatile__("sti");
    puts("System Start!\n");

    for(;;);
}
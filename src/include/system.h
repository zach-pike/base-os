#ifndef __SYSTEM_H
#define __SYSTEM_H

#define NULL 0

typedef char int8_t;
typedef short int16_t;
typedef int int32_t;
typedef long long int64_t;

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef unsigned long long uint64_t;

typedef void * type_t;

extern void cls();
extern void putch(char c);
extern void puts(const char *str);
void write_hex(uint32_t n);
void write_dec_str(uint32_t n);
extern void settextcolor(uint8_t forecolor, uint8_t backcolor);
extern void init_video();

extern void gdt_install();
extern void idt_install();
extern void isrs_install();

typedef struct regs
{
    uint32_t gs, fs, es, ds;
    uint32_t edi, esi, ebp, esp, ebx, edx, ecx, eax;
    uint32_t int_no, err_code;
    uint32_t eip, cs, eflags, useresp, ss;
} register_t;

void irq_install_handler(int32_t irq, void (*handler)(register_t *r));
void irq_uninstall_handler(int32_t irq);
void irq_install();

void irs_install_handler(int32_t irs, void (*handler)(register_t *r));

void timer_install(uint32_t frequency);

void idt_set_gate(uint8_t num, uint32_t base, uint16_t sel, uint8_t flags);

void keyborad_install();

#endif
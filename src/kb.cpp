#include "include/system.h"
#include "include/basic.h"

uint8_t kbdus[128] = {
    0,  27, '1', '2', '3', '4', '5', '6', '7', '8',	/* 9 */
  '9', '0', '-', '=', '\b',	/* Βackspace */
  '\t',			/* Τab */
  'q', 'w', 'e', 'r',	/* 19 */
  't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\n',	/* Εnter key */
    0,			/* 29   - Control */
  'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';',	/* 39 */
 '\'', '`',   0,		/* Left shift */
 '\\', 'z', 'x', 'c', 'v', 'b', 'n',			/* 49 */
  'm', ',', '.', '/',   0,				/* Right shift */
  '*',
    0,	/* Αlt */
  ' ',	/* Space bar */
    0,	/* Caps lock */
    0,	/* 59 - F1 key ... > */
    0,   0,   0,   0,   0,   0,   0,   0,
    0,	/* < ... F10 */
    0,	/* 69 - Νum lock*/
    0,	/* Scroll Lock */
    0,	/* Ηome key */
    0,	/* Up Αrrow */
    0,	/* Ρage Up */
  '-',
    0,	/* Left Αrrow */
    0,
    0,	/* Right Αrrow */
  '+',
    0,	/* 79 - Εnd key*/
    0,	/* Down Αrrow */
    0,	/* Ρage Down */
    0,	/* Ιnsert Κey */
    0,	/* Delete Κey */
    0,   0,   0,
    0,	/* F11 Κey */
    0,	/* F12 Κey */
    0,	/* Αll other keys are undefined */
};

void keyboard_handler(register_t *r)
{
    uint8_t scancode;

    scancode = inportb(0x60);

    if (scancode & 0x80)
    {

    }
    else
    {
        putch(kbdus[scancode]);
    }
    
}

void keyborad_install(void)
{
    irq_install_handler(1, keyboard_handler);
}
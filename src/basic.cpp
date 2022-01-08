#include <basic.h>

uint8_t *memcpy(uint8_t *dest, const uint8_t *src, int32_t count) {
    const char *sp = (const char *)src;
    char *dp = (char *)dest;
    while (count > 0) {
        *dp++ = *sp++;
        count--;
    }
    return dest;
}

uint8_t *memset(uint8_t *dest, uint8_t val, int32_t count) {
    char *temp = (char *)dest;
    while (count > 0) {
        *temp++ = val;
        count--;
    }
    return dest;
}

uint16_t *memsetw(uint16_t *dest, uint16_t val, int32_t count) {
    uint16_t *temp = (uint16_t *)dest;
    while (count > 0) {
        *temp++ = val;
        count--;
    }
    return dest;
}

int32_t strlen(const char *str) {
    int32_t retval;
    for (retval = 0; *str != '\0'; str++)
        retval++;
    return retval;
}

uint8_t inportb(uint16_t _port) {
    uint8_t rv;
    __asm__ __volatile__("inb %1, %0" : "=a" (rv) : "dN" (_port));
    return rv;
}

void outportb(uint16_t _port, uint8_t _data) {
    __asm__ __volatile__("outb %1, %0" : : "dN" (_port), "a" (_data));
}
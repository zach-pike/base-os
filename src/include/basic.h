#ifndef __BASIC_H
#define __BASIC_H

#include "system.h"

uint8_t *memcpy(uint8_t *dest, const uint8_t *src, int32_t count);

uint8_t *memset(uint8_t *dest, uint8_t val, int32_t count);

uint16_t *memsetw(uint16_t *dest, uint16_t val, int32_t count);

int32_t strlen(const char *str);

uint8_t inportb(uint16_t _port);

void outportb(uint16_t _port, uint8_t _data);

#endif
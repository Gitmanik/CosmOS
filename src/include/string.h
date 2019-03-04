#pragma once

#include <stddef.h>

size_t strlen(const char* str);

void* memset(void* bufptr, int value, size_t size);
void* memcpy(void* restrict dstptr, const void* restrict srcptr, size_t size);
char* itoa(int num, char* str, int base);
/**
 * @Author: Paweł Reich <Gitmanik>
 * @Date:   2019-03-03T12:52:59+01:00
 * @Email:  thegitman@outlook.com
 * @Project: CosmOS
 * @Filename: string.h
 * @Last modified by:   Gitmanik
 * @Last modified time: 2019-03-03T13:37:55+01:00
 */

#pragma once
#include <stddef.h>

size_t strlen(const char* str);

void* memset(void* bufptr, int value, size_t size);
void* memcpy(void* restrict dstptr, const void* restrict srcptr, size_t size);

/**
 * @Author: Paweł Reich <Gitmanik>
 * @Date:   2019-03-03T12:52:52+01:00
 * @Email:  thegitman@outlook.com
 * @Project: CosmOS
 * @Filename: string.c
 * @Last modified by:   Gitmanik
 * @Last modified time: 2019-03-03T12:53:30+01:00
 */

#include "string.h"

 size_t strlen(const char* str)
 {
 	size_t len = 0;
 	while (str[len])
 		len++;
 	return len;
 }

/**
 * @Author: Paweł Reich <Gitmanik>
 * @Date:   2019-03-03T16:38:06+01:00
 * @Email:  thegitman@outlook.com
 * @Project: CosmOS
 * @Filename: inlineassembly.h
 * @Last modified by:   Gitmanik
 * @Last modified time: 2019-03-03T17:53:40+01:00
 */

#pragma once

void outb(uint16_t port, uint8_t val);
uint8_t inb(uint16_t port);

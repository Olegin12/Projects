/*
 * CRC32.h
 *
 *  Created on: 6 сент. 2017 г.
 *      Author: gleb.maslennikov
 */

#ifndef CRC32_H_
#define CRC32_H_

#include "stm32f1xx_hal.h"
#include <stdbool.h>

uint32_t crc32(const void *buf, uint16_t size);

bool check_crc16( const uint8_t *array, uint16_t len, uint32_t crc);

uint16_t add_crc16(uint8_t *array, uint16_t len);

#endif /* CRC32_H_ */

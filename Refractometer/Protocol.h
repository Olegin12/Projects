/*
 * Protocol.h
 *
 *  Created on: 6 сент. 2017 г.
 *      Author: gleb.maslennikov
 */

#ifndef PROTOCOL_H_
#define PROTOCOL_H_

#include "main.h"
#include "CRC32.h"

#define HEADER_LENGTH	12
#define CRC_LENGTH			4

#define FRAME_LENGTH  HEADER_LENGTH + CRC_LENGTH

#define ADDR				0x0015
#define GET_INFO			0x0001
#define GET_INFO_ACK		0x0002
#define GET_STATUS			0x0003
#define GET_STATUS_ACK		0x0004
#define SET_BURN_PARAMS		0x0005
#define SET_BURN_PARAMS_ACK	0x0006
#define BURN				0x0007
#define BURN_BEGIN_ACK		0x0008
#define BURN_DATA			0x0009
#define BURN_DATA_ACK		0x000A
#define BURN_END			0x000B
#define BURN_END_ACK		0x000C
#define BREAK_BURN			0x000D
#define BREAK_BURN_ACK		0x000E


typedef struct
{
	uint16_t message_id;
	uint16_t command_id;
	uint16_t data_len;
} message_header;

typedef enum {
	ready_status = 1,
	work_status = 2,
	idle_status = 8,
	paused_status = 14
}tool_status ;

void message_box(uint8_t* Buf, uint16_t len);

uint16_t message_header_to_array(const message_header* message, uint8_t* Buf);

void send_data(uint8_t* Buf);

void data_end();

#endif /* PROTOCOL_H_ */

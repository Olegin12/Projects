/*
 * Protocol.c
 *
 *  Created on: 6 сент. 2017 г.
 *      Author: gleb.maslennikov
 */

#include "Protocol.h"

uint8_t messege_box_buffer[32];
//extern uint16_t adc_data_buffer[3700];
message_header message;
uint16_t command = 0;
uint16_t tx_len = 0;
uint8_t burn_param[5];

void message_box(uint8_t* Buf, uint16_t len) {

	command = Buf[6] | (uint16_t) Buf[7] << 8;
	message.data_len = 0;
	message.message_id = Buf[4] | (uint16_t) Buf[5] << 8;

uint16_t burn_time;
uint16_t burn_points;


	switch (command) {
	case GET_INFO:
		message.command_id = GET_INFO_ACK;
		tx_len = message_header_to_array(&message, messege_box_buffer);
		break;

	case GET_STATUS:
		message.command_id = GET_STATUS_ACK;
		tx_len = message_header_to_array(&message, messege_box_buffer);
		break;

	case SET_BURN_PARAMS:
        memmove(burn_param + 0, Buf + 10, 5);
        memmove(messege_box_buffer + 10, burn_param + 0, 5);
		message.command_id = SET_BURN_PARAMS_ACK;
		message.data_len = 5;
		tx_len = message_header_to_array(&message, messege_box_buffer);
		break;

	case BURN:
		message.command_id = BURN_BEGIN_ACK;
		memmove(messege_box_buffer + 10, burn_param + 0, 5);
		message.data_len = 5;
		tx_len = message_header_to_array(&message, messege_box_buffer);
		burn_time = burn_param[0] | (uint16_t) Buf[1] << 8;
		burn_points = burn_param[2] | (uint16_t) Buf[3] << 8;
		set_start_burn(true, burn_time, burn_points);
		//CDC_Transmit_FS(messege_box_buffer, tx_len);

		break;

	case BURN_DATA:
		message.data_len = 7400;
		message.command_id = BURN_DATA_ACK;
		tx_len = message_header_to_array(&message, messege_box_buffer);
		break;

	case BURN_END:
		message.command_id = BURN_END_ACK;
		tx_len = message_header_to_array(&message, messege_box_buffer);
		break;

	case BREAK_BURN:
		message.command_id = BREAK_BURN_ACK;
		tx_len = message_header_to_array(&message, messege_box_buffer);
		break;

	default:
		tx_len = message_header_to_array(&message, messege_box_buffer);
		break;
	}

	CDC_Transmit_FS(messege_box_buffer, tx_len);
	//CDC_Transmit_FS(messege_box_buffer, tx_len);

}

uint16_t message_header_to_array(const message_header* message, uint8_t* Buf) {
	Buf[0] = ADDR;
	Buf[1] = ADDR >> 8;
	Buf[2] = ADDR >> 16;
	Buf[3] = ADDR >> 24;
	Buf[4] = message->message_id;
	Buf[5] = message->message_id >> 8;
	Buf[6] = message->command_id;
	Buf[7] = message->command_id >> 8;

	Buf[8] = 0; //reserved lsb
	Buf[9] = 0; //reserved msb

	Buf[10] = message->data_len;
	Buf[11] = message->data_len >> 8;

	uint32_t crc = crc32(Buf, HEADER_LENGTH);

	Buf[12] = crc;
	Buf[13] = crc >> 8;
	Buf[14] = crc >> 16;
	Buf[15] = crc >> 24;

	uint16_t message_len = 0;
	message_len = HEADER_LENGTH + message->data_len + CRC_LENGTH;

	crc = crc32(Buf + 16, message->data_len);

    if(message->data_len != 0){
	Buf[message_len] = crc;
	Buf[message_len + 1] = crc >> 8;
	Buf[message_len + 2] = crc >> 16;
	Buf[message_len + 3] = crc >> 24;
	message_len += CRC_LENGTH;
    }

	return message_len;
}

void send_data(uint8_t* Buf){
	message.data_len = 7400;
	message.command_id = BURN_DATA_ACK;
	tx_len = message_header_to_array(&message,  Buf);
	CDC_Transmit_FS( Buf, tx_len);
}

void data_end(){
	message.data_len = 0;
	message.command_id = BURN_END_ACK;
	tx_len = message_header_to_array(&message, messege_box_buffer);
	CDC_Transmit_FS(messege_box_buffer, tx_len);
}

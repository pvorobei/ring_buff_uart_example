/*
 * usart_ring.h
 *
 *  Created on: 19 авг. 2021 г.
 *      Author: ivan
 */

#ifndef USART_RING_H_
#define USART_RING_H_

#include "main.h"

#define MYUART huart1 // задефайнить USART
#define UART_RX_BUFFER_SIZE 128 // указать размер приёмного буфера

uint16_t uart_available(void);
uint8_t uart_read(void);
void clear_uart_buff();

#endif /* USART_RING_H_ */


















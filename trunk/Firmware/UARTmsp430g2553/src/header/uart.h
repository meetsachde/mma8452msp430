/*
 * uart.h
 *
 *  Created on: 13 Aug 2012
 *      Author: Cu Xuan Duc
 */

#ifndef UART_H_
#define UART_H_

void uart_init(void);
void TimerA_UART_tx(unsigned char byte);	//uart_putc(char c)
void TimerA_UART_print(char *string);		//uart_puts(char *s)

#endif /* UART_H_ */

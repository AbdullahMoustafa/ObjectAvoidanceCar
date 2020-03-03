/*
 * UART.h
 *
 *  Created on: Nov 25, 2019
 *      Author: kino
 */

#ifndef UART_H_
#define UART_H_
#define RCGCUART (*((volatile unsigned long*)0x400FE618))
#define UARTIBRD (*((volatile unsigned long*)0x4000F024))
#define UARTFBRD (*((volatile unsigned long*)0x4000F028))
#define UARTLCRH (*((volatile unsigned long*)0x4000F02C))
#define UARTCTL (*((volatile unsigned long*)0x4000F030))
#define UARTCC (*((volatile unsigned long*)0x4000FFC8))
#define UARTDMACTL (*((volatile unsigned long*)0x4000F048))
#define UARTFR (*((volatile unsigned long*)0x4000F018))
#define UARTDR (*((volatile unsigned long*)0x4000F000))
#define UARTIM (*((volatile unsigned long*)0x4000F038))
#define UARTMIS (*((volatile unsigned long*)0x4000F040))
#define UARTICR (*((volatile unsigned long*)0x4000F044))
#define UARTIFLS (*((volatile unsigned long*)0x4000F034))
#define EN1 (*((volatile unsigned long*)0xE000E104))
//*******************************************************************************
void UART_Initialization(void);
u8 read (void);
void write (u8 x);
void write_string(u8 *ptr);



#endif /* UART_H_ */

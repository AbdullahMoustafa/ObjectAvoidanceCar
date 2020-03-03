/*
 * UART.c
 *
 *  Created on: Nov 25, 2019
 *      Author: kino
 */

#include"util.h"
#include"stdtypes.h"
#include "GPIO.h"
#include"UART .h"
void UART_Initialization(void){
    SET_BIT(RCGCUART,3);  //enable UART3
    SET_BIT(RCGCGPIO,2);  // enable clock to portC
    unsigned long delay1_C=RCGCGPIO;
    GPIOLOCK_C=0x4C4F434B; //UNLOCK PORTC
    SET_BIT(GPIOCR_C,6);   //Enable PC6,PC7 TO CONTROL ALTERNTIVE FUNC
    SET_BIT(GPIOCR_C,7);
    SET_BIT(GPIOAFSEL_C,6); //PC6 PC7 to alternative function (UART0)
    SET_BIT(GPIOAFSEL_C,7);
    SET_BIT(GPIOPCTL_C,24); //pins is working in UART mode
    SET_BIT(GPIOPCTL_C,28);
    SET_BIT(GPIODEN_C,6);  //enable  PC6,PC7
    SET_BIT(GPIODEN_C,7);
    SET_BIT(UARTIM,4); // to enable receive interrupt
    SET_BIT(UARTIM,5); // to enable transmit interrupt
    SET_BIT(EN1,27); //to enable the uart3 interrupt using NVIC
    CLR_BIT(UARTCTL,0); //disable UART
    UARTIBRD=26;//configuring the baud rate 9600
    UARTFBRD=27;
    UARTLCRH=(0x3<<5); // start,, data(8-bit) ,, stop(1-bit),,no parity
    SET_BIT(UARTLCRH,4); // enabling FIFO
    CLR_BIT(UARTIFLS,1); //making FIFO transmission length = 14 bytes at a time
    CLR_BIT(UARTIFLS,4); //making FIFO receive length = 2 bytes at a time
    UARTCC=0x0;
    SET_BIT(UARTCTL,0); // enabling UART
    SET_BIT(UARTCTL,8); // enabling TX
    SET_BIT(UARTCTL,9); //enabling RX
}
u8 read (void)
{
    u8 res;
    res=UARTDR;
    return res;
}
void write (u8 x)
{
    UARTDR=(x);

}
void write_string(u8 *ptr)
{
    u8 i=0;
    while (ptr[i] != '\0')
    {
        write(ptr[i]);
        i++;
    }
}



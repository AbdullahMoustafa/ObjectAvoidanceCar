/*
 * PWM.c
 *
 *  Created on: Jan 28, 2020
 *      Author: Abdullah
 */
#include"util.h"
#include"stdtypes.h"
#include "GPIO.h"
#include"PWM.h"

void PWM_Init()
{
    CLR_BIT(RCC,20);                    //use the same system clock 16 MHZ without any divison.
    SET_BIT(RCGC0,20);                  // Enable Clock of PWM0
    SET_BIT(RCGC2,1);                   // Enable clock to GPIOB because we use PORTB ---> PB6
    unsigned long delay0=RCGC2;         // Delay to make sure that clock is stable
    SET_BIT(RCGCGPIO,1);                // enable clock to portB
    unsigned long delay1_B=RCGCGPIO;    // Delay to make sure that clock is stable
    GPIOLOCK_B=0x4C4F434B;              //UNLOCK PORTB
    SET_BIT(GPIOCR_B,6);                //Enable GPIODEN & GPIOAFSEL Registers for PB6
    SET_BIT(GPIODEN_B,6);               //enable  PB6
    SET_BIT(GPIOAFSEL_B,6);             // PB6 to alternative function
    GPIOPCTL_B&=~(0x0F000000);
    GPIOPCTL_B|=(0x04000000);           //pins is working in PWM mode by puting value (4) in PMC6
    CLR_BIT(PWM0CTL,0);                 // Disable PWM0
    //SET_BIT(PWM0CTL,1);                 //The counter counts up from 0 to the load value, back down to 0, and then repeats (Count-Up/Down mode).
    PWM0GENA|=0x8C;
    PWM0LOAD=16000;
    PWM0CMPA=15999;
    //    PWM0CMPA=x;
    PWM0CTL|=0x01;                   //Enable PWM0
    PWMENABLE=0x00000001;            //Enable PWM output



}

unsigned long Number_OF_Ticks(unsigned long Frequency)
{
    unsigned long Period=1/Frequency;
    unsigned long Ticks=(Period*(16000000))-1;
    return Ticks;
}

void change_duty(f32 Duty_cycle)
{
    u32 x;
    x=(1-Duty_cycle)*16000;
    PWM0CMPA=x;



}
unsigned long Duty_FUNCTION(unsigned long DutyCycle,unsigned long Frequency)
{
    unsigned long compA=(((1/Frequency)*16000000)*(DutyCycle))-1;
    return compA;

    /* unsigned long Period=1/Frequency;
     unsigned long Ticks=Period*16000000;
     unsigned long comp=DutyCycle*Ticks;
     unsigned long compA=comp-1;
     return compA;*/

}


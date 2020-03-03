/*
 * PWM.h
 *
 *  Created on: Jan 28, 2020
 *      Author: Abdullah
 */

#ifndef PWM_H_
#define PWM_H_
#define RCGC0 (*((volatile unsigned long*)0x400FE100))
#define RCGC2 (*((volatile unsigned long*)0x400FE108))
#define RCC (*((volatile unsigned long*)0x400FE060))
#define PWM0CTL (*((volatile unsigned long*)0x40028040))
#define PWM0GENA (*((volatile unsigned long*)0x40028060))
#define PWM0GENB (*((volatile unsigned long*)0x40028064))
#define PWM0LOAD (*((volatile unsigned long*)0x40028050))
#define PWM0CMPA (*((volatile unsigned long*)0x40028058))
#define PWM0CMPB (*((volatile unsigned long*)0x4002805C))
#define PWMENABLE (*((volatile unsigned long*)0x40028008))
//*********************************************************************************************


void PWM_Init();
unsigned long Number_OF_Ticks(unsigned long Frequency);
unsigned long Duty_FUNCTION(unsigned long DutyCycle,unsigned long Frequency);
void change_duty(f32 Duty_cycle);



#endif /* PWM_H_ */
